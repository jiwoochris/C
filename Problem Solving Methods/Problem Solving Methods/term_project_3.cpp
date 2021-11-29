//
//struct REGISTRATIONS
//{
//    int tag;
//    char *date;
//    char *is_fee_paid;
//    char *name;
//    int age;
//    char *org;
//    char *job;
//    struct REGISTRATIONS *next;
//};
//
//
//
//
//
///* 5-1. Write sorted data to text file. */
//bool ifFileWritten(const char *file_name, struct REGISTRATIONS registrations[])
//{
//    printf("------------------------------------\n");
//    printf("%25s", "Writing file\n");
//    printf("------------------------------------\n");
//
//    // declare file
//    FILE *file;
//
//    // open file in write mode
//    file = fopen(file_name, "w");
//
//    // file not present
//    if (file == NULL)
//    {
//        printf("Opening %s failed!\n", file_name);
//        printDashes(DASH_NUM);
//        return false;
//    }
//
//    // file present
//    printf("Opening %s success!\n", file_name);
//    printDashes(DASH_NUM);
//    for (int i = 0; i < MAX_REGISTRATION_NUM; i++)
//    {
//        // write structure data to file
//        fprintf(file, "Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
//                registration[i].tag, registration[i].date, registration[i].is_fee_paid, registration[i].name, registration[i].age, registration[i].org, registration[i].job);
//    }
//    printDashes(DASH_NUM);
//
//    // close file
//    fclose(file);
//
//    return true;
//}
//
//
//
///* 1-1. Search for "Choi". (Array) */
///* 2-1. Search for "Gachon University". (Array) */
//void searchArray(char *string, char *search, int i)
//{
//    int len_str = strlen(string);
//    int len_search = strlen(search);
//    int count = 0;
//
//    // for loop (1 through string length)
//    for (int cursor = 0; cursor < len_str - len_search + 1; cursor++)
//    {
//        // if first character of search-string found
//        if (string[cursor] == search[0])
//        {
//            // for loop (1 through length of search-string)
//            bool found = true;
//            for (int i = 1; i < len_search; i++)
//            {
//                // if substring matches the search-string, found
//                if (string[cursor + i] != search[i])
//                {
//                    found = false;
//                    break;
//                }
//            }
//
//            // match found
//            if (found)
//            {
//                printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
//                       registration[i].tag, registration[i].date, registration[i].is_fee_paid, registration[i].name, registration[i].age, registration[i].org, registration[i].job);
//                count++;
//            }
//        }
//    }
//}
//
///* 1-2. Search for "Choi". (Linked List) */
///* 2-2. Search for "Gachon University". (Linked List) */
//bool searchNode(struct REGISTRATIONS *head, char *search_name)
//{
//    // initialize current
//    struct REGISTRATIONS *current = head;
//
//    while (current != NULL)
//    {
//        // match found
//        if (strcmp(current->name, search_name) == 0)
//        {
//            printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
//                   head->tag, head->date, head->is_fee_paid, head->name, head->age, head->org, head->job);
//            return true;
//        }
//
//        current = current->next;
//    }
//
//    return false;
//}
//
///* 4-2. Sort data in age order. (Selection sort) */
//struct REGISTRATIONS *selectionSort(struct REGISTRATIONS *head)
//{
//    struct REGISTRATIONS *a, *b, *c, *d, *r;
//
//    a = b = head;
//
//    while (b->next)
//    {
//        c = d = b->next;
//        while (d)
//        {
//            if (b->age > d->age)
//            {
//                if (b->next == d)
//                {
//                    if (b == head)
//                    {
//                        b->next = d->next;
//                        d->next = b;
//                        r = b;
//                        b = d;
//                        d = r;
//                        c = d;
//                        head = b;
//                        d = d->next;
//                    }
//                    else
//                    {
//                        b->next = d->next;
//                        d->next = b;
//                        a->next = d;
//                        r = b;
//                        b = d;
//                        d = r;
//                        c = d;
//                        d = d->next;
//                    }
//                }
//                else
//                {
//                    if (b == head)
//                    {
//                        r = b->next;
//                        b->next = d->next;
//                        d->next = r;
//                        c->next = b;
//                        r = b;
//                        b = d;
//                        d = r;
//                        c = d;
//                        d = d->next;
//                        head = b;
//                    }
//
//                    else
//                    {
//                        r = b->next;
//                        b->next = d->next;
//                        d->next = r;
//                        c->next = b;
//                        a->next = d;
//                        r = b;
//                        b = d;
//                        d = r;
//                        c = d;
//                        d = d->next;
//                    }
//                }
//            }
//            else
//            {
//                c = d;
//                d = d->next;
//            }
//        }
//        a = b;
//        b = b->next;
//    }
//    return head;
//}