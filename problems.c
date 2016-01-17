#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

void test_ll() {
    struct node* mylist = NULL;
    mylist = malloc(sizeof(struct node));

    mylist = build_new();
    push(&mylist, 4);
    append(&mylist, 5);
    print_elements(mylist);
    insert(&mylist, 5, 7);

    print_elements(mylist);
    int len = list_len(mylist);
    printf("Length of the list: %d\n", len);
}

int count_instances(struct node* head, int needle) {
    int counter = 0;
    while (head != NULL) {
        if (head->data == needle)
            counter++;
        head = head->next;
    }
    return counter;
}

void test_count_instances() {
    struct node* mylist = build_new();
    push(&mylist, 2);
    push(&mylist, 2);
    int needle = 2;
    int instances = count_instances(mylist, needle);

    printf("count of %d: %d\n", needle, instances);
}

void test_getNth() {
    int index = 1;
    struct node* mylist = build_new();
    int data = get_data_at(mylist, index);
    printf("data at %d: %d\n", index, data);
}

int main() {
    puts("All problems will be solved here !!");
    test_getNth();
    return 0;
}
