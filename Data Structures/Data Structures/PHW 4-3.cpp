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

/* global variable, so sue me */
int visited;

void nearest(struct kd_node_t* root, struct kd_node_t* nd, int i, int dim,
    struct kd_node_t** best, double* best_dist)
{
    double d, dx, dx2;

    if (!root) return;
    d = dist(root, nd, dim);
    dx = root->x[i] - nd->x[i];
    dx2 = dx * dx;

    visited++;

    if (!*best || d < *best_dist) {
        *best_dist = d;
        *best = root;
    }

    /* if chance of exact match is high */
    if (!*best_dist) return;

    if (++i >= dim) i = 0;

    nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);
    if (dx2 >= *best_dist) return;
    nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);
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

        if (same == true) {
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

    if (same == true)
        printf("In the range : (%g, %g)\n", root->x[0], root->x[1]);

    if(BR_left->x[i] <= root->x[i] || BR_right->x[i] <= root->x[i])
        range_search(root->left, BR_left, BR_right, (i + 1) % dim, 2);

    if (BR_left->x[i] >= root->x[i] || BR_right->x[i] >= root->x[i])
        range_search(root->right, BR_left, BR_right, (i + 1) % dim, 2);
}

int main(void)
{
    struct kd_node_t wp[] = {
        {{2, 3}}, {{5, 4}}, {{3,4}}, { {9, 6}}, {{4,7}}, {{8,1}}, {{7,2}}
    };
    struct kd_node_t testNode = { {9, 2} };
    struct kd_node_t* root, * found;
    double best_dist;

    root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);

    visited = 0;
    found = 0;
    nearest(root, &testNode, 0, 2, &found, &best_dist);

    printf(">> WP tree\nsearching for (%g, %g)\n"
        "found (%g, %g) dist %g\nseen %d nodes\n\n",
        testNode.x[0], testNode.x[1],
        found->x[0], found->x[1], sqrt(best_dist), visited);



    printf("\n\nPoint Search\n\n");

    struct kd_node_t testNode1 = { {5, 4} };
    struct kd_node_t testNode2 = { {4, 7} };
    struct kd_node_t testNode3 = { {10, 5} };

    point_search(root, &testNode1, 0, 2);
    point_search(root, &testNode2, 0, 2);
    point_search(root, &testNode3, 0, 2);

    printf("\n\nRange Search\n\n");

    struct kd_node_t BR_left = { {6, 3} };
    struct kd_node_t BR_right = { {9, 7} };

    range_search(root, &BR_left, &BR_right, 0, 2);
    




    return 0;
}