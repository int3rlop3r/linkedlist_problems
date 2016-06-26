#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ll.h"

void test_ll() {
    struct node *mylist = NULL;
    mylist = (struct node *) malloc(sizeof(struct node));

    mylist = build_new();
    lpush(&mylist, 4);
    lappend(&mylist, 5);
    lprint(mylist);
    linsert(&mylist, 5, 7);

    lprint(mylist);
    int len = llen(mylist);
    printf("Length of the list: %d\n", len);
}

void test_count() {
    puts("Running Question 1");
    struct node *mylist = build_new();
    lpush(&mylist, 2);
    lpush(&mylist, 2);
    int needle = 2;
    int instances;
    instances = lcount(mylist, needle);
    assert(instances == 3);
    puts("Passed");
}

void test_getnth() {
    puts("Running Question 2");
    int index = 1;
    struct node *mylist = build_new();
    int data;
    data = lget(mylist, index);
    assert(data == 2);
    puts("Passed");
}

void test_delete_list() {
    puts("Running Question 3");
    struct node *mylist = build_new();
    int ll = llen(mylist);
    assert(ll == 3);
    ldelete(&mylist);
    ll = llen(mylist);
    assert(ll == 0);
    puts("Passed");
}

void test_pop() {
    puts("Running Question 4");
    struct node *mylist = build_new();
    int ll = llen(mylist);
    int data = lpop(&mylist);
    assert(data == 1);
    data = lpop(&mylist);
    assert(data == 2);
    data = lpop(&mylist);
    assert(data == 3);
    ll = llen(mylist);
    assert(ll == 0);
    puts("Passed");
}

void test_insert() {
    puts("Running Question 5");
    struct node *mylist = NULL;
    linsert(&mylist, 0, 13);
    linsert(&mylist, 1, 42);
    linsert(&mylist, 1, 5);
    int ll = llen(mylist);
    assert(ll == 3);
    int data_at_1;
    data_at_1 = lget(mylist, 1);
    assert(data_at_1 == 5);
    ldelete(&mylist);
    ll = llen(mylist);
    assert(ll == 0);
    puts("Passed");
}

void test_sorted_insert() {
    puts("Running Question 6");
    struct node *mylist = NULL;
    lpush(&mylist, 5);
    lpush(&mylist, 4);
    lpush(&mylist, 2);
    lpush(&mylist, 1);
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = 3;
    new_node->next = NULL;
    lsorted_insert(&mylist, new_node);
    int ll = llen(mylist);
    assert(ll == 5);
    int data = lget(mylist, 2);
    assert(data == 3);
    puts("Passed");
}

int main() {
    puts("All problems will be solved here !!");
    test_count();
    test_getnth();
    test_delete_list();
    test_pop();
    test_insert();
    test_sorted_insert();
    return 0;
}
