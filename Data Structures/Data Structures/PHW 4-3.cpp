#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DIM 3
struct kd_node_t {
    double x[MAX_DIM];
    struct kd_node_t* left, * right;
};

inline double dist(struct kd_node_t* a, struct kd_node_t* b, int dim)
{
    double t, d = 0;
    while (dim--) {
        t = a->x[dim] - b->x[dim];
        d += t * t;
    }
    return d;
}
inline void swap(struct kd_node_t* x, struct kd_node_t* y) {
    double tmp[MAX_DIM];
    memcpy(tmp, x->x, sizeof(tmp));
    memcpy(x->x, y->x, sizeof(tmp));
    memcpy(y->x, tmp, sizeof(tmp));
}


/* see quickselect method */
struct kd_node_t* find_median(struct kd_node_t* start, struct kd_node_t* end, int idx)
{
    if (end <= start) return NULL;
    if (end == start + 1)
        return start;

    struct kd_node_t* p, * store, * md = start + (end - start) / 2;
    double pivot;
    while (1) {
        pivot = md->x[idx];

        swap(md, end - 1);
        for (store = p = start; p < end; p++) {
            if (p->x[idx] < pivot) {
                if (p != store)
                    swap(p, store);
                store++;
            }
        }
        swap(store, end - 1);

        /* median has duplicate values */
        if (store->x[idx] == md->x[idx])
            return md;

        if (store > md) end = store;
        else        start = store;
    }
}

struct kd_node_t* make_tree(struct kd_node_t* t, int len, int i, int dim)
{
    struct kd_node_t* n;

    if (!len) return 0;

    if ((n = find_median(t, t + len, i))) {
        i = (i + 1) % dim;
        n->left = make_tree(t, n - t, i, dim);
        n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
    }
    return n;
}

void point_search(struct kd_node_t* root, struct kd_node_t* key_node, int i, int dim) {
    if (root == NULL)
        printf("Search Failed : (%g, %g)\n", key_node->x[0], key_node->x[1]);

    else {
        bool same = true;
        for (int i = 0; i < dim; i++) {
            if (root->x[i] != key_node->x[i])
                same = false;
        }

        if (same == true) {     // if search success
            printf("Search Success : (%g, %g)\n", key_node->x[0], key_node->x[1]);
        }
        else {
            point_search(key_node->x[i] <= root->x[i] ? root->left : root->right,
                key_node, (i+1)%dim, 2);
        }
    }
}

void range_search(struct kd_node_t* root, struct kd_node_t* BR_left, struct kd_node_t* BR_right,int i, int dim) {
    if (root == NULL)
        return;

    bool same = true;
    for (int i = 0; i < dim; i++) {
        if (!(BR_left->x[i] <= root->x[i] && root->x[i] <= BR_right->x[i]))
            same = false;
    }

    if (same == true)     // if node is in the BR
        printf("In the range : (%g, %g)\n", root->x[0], root->x[1]);

    if(BR_left->x[i] <= root->x[i] || BR_right->x[i] <= root->x[i])     // if node's left side contains in the BR
        range_search(root->left, BR_left, BR_right, (i + 1) % dim, 2);

    if (BR_left->x[i] >= root->x[i] || BR_right->x[i] >= root->x[i])     // if node's right side contains in the BR
        range_search(root->right, BR_left, BR_right, (i + 1) % dim, 2);
}

/* global variable, so sue me */
int visited = 0;
bool search_leaf_level(struct kd_node_t* root, struct kd_node_t* key_node, int i, int dim) {     // simullar to point search, to find leaf node

    visited++;     // measure the level of tree

    if (root == NULL)
        return false;

    else {
        bool same = true;
        for (int i = 0; i < dim; i++) {
            if (root->x[i] != key_node->x[i])
                same = false;
        }

        if (same == true) {     // if point search success
            return true;
        }
        else {
            return search_leaf_level(key_node->x[i] <= root->x[i] ? root->left : root->right,
                key_node, (i + 1) % dim, 2);
        }
    }
}

struct kd_node_t** find_new_root(struct kd_node_t* root, struct kd_node_t* key_node, int i, int dim, int level) {     // leaf nodes go up to 2 level parent node
    visited++;

    if (visited == level)
        return &root;

    else
        return find_new_root(key_node->x[i] <= root->x[i] ? root->left : root->right, key_node, (i + 1) % dim, dim, level);
}


double nearest_distance = 9999;
struct kd_node_t nearest_point;

void calculate_subtree_distance(struct kd_node_t* root, struct kd_node_t* key_node) {     // calculate all nodes of subtree
    
    if (root) {
        calculate_subtree_distance(root->left, key_node);

        double distance = sqrt(pow(root->x[0] - key_node->x[0], 2) + pow(root->x[1] - key_node->x[1], 2));     // if it is  closer than current one, update nearest information
        if (distance < nearest_distance) {
            nearest_distance = distance;
            nearest_point.x[0] = root->x[0];
            nearest_point.x[1] = root->x[1];
        }

        calculate_subtree_distance(root->right, key_node);
    }
}

void nearest_neighbor_search(struct kd_node_t* root, struct kd_node_t* key_node, int i, int dim) {
    visited = 0;
    if (search_leaf_level(root, key_node, i, dim))
        printf("(%g, %g)'s nearest neighbor is (%g, %g), distance = 0\n", key_node->x[0], key_node->x[1], nearest_point.x[0], nearest_point.x[1]);

    else {
        struct kd_node_t** new_root;
        int level = visited - 3;
        
        visited = 0;
        new_root = find_new_root(root, key_node, i, dim, level);    // Find new root by doing Point_search and stop when the node's level is L-2

        calculate_subtree_distance(*new_root, key_node);

        printf("(%g, %g)'s nearest neighbor is (%g, %g), distance = %lf\n", key_node->x[0], key_node->x[1], nearest_point.x[0], nearest_point.x[1], nearest_distance);
    }
}

int main(void)
{
    struct kd_node_t wp[] = {
        {{2, 3}}, {{5, 4}}, {{3,4}}, { {9, 6}}, {{4,7}}, {{8,1}}, {{7,2}}
    };
    struct kd_node_t testNode = { {9, 2} };
    struct kd_node_t* root;

    root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);


    // Point Search
    printf("\n\nPoint Search\n\n");

    struct kd_node_t testNode1 = { {5, 4} };
    struct kd_node_t testNode2 = { {4, 7} };
    struct kd_node_t testNode3 = { {10, 5} };

    point_search(root, &testNode1, 0, 2);
    point_search(root, &testNode2, 0, 2);
    point_search(root, &testNode3, 0, 2);


    // Range Search
    printf("\n\nRange Search\n\n");
    struct kd_node_t BR_left = { {6, 3} };
    struct kd_node_t BR_right = { {9, 7} };

    range_search(root, &BR_left, &BR_right, 0, 2);


    // Nearest Neighbor Search
    printf("\n\nNearest Neighbor Search\n\n");

    struct kd_node_t testNode4 = { {5, 4} };
    struct kd_node_t testNode5 = { {4, 7} };
    struct kd_node_t testNode6 = { {6, 1} };

    nearest_neighbor_search(root, &testNode4, 0, 2);
    nearest_neighbor_search(root, &testNode5, 0, 2);
    nearest_neighbor_search(root, &testNode6, 0, 2);

    return 0;
}