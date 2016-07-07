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
    int ll = 0;
    int elem;

    /*when elem has to be added at the end*/
    lpush(&mylist, 8);
    lpush(&mylist, 6);
    lpush(&mylist, 5);
    lpush(&mylist, 4);
    lpush(&mylist, 9);
    lpush(&mylist, 1);

    lsorted_insert(&mylist, mylist->next);
    ll = llen(mylist);
    assert(ll == 6);
    assert(lget(mylist, 1) == 4); // starts with zero
    assert(lget(mylist, 5) == 9); // starts with zero

    /*when elem lands up somewhere in between*/
    struct node *mylist2 = NULL;
    lpush(&mylist2, 8);
    lpush(&mylist2, 6);
    lpush(&mylist2, 5);
    lpush(&mylist2, 4);
    lpush(&mylist2, 7);
    lpush(&mylist2, 1);

    lsorted_insert(&mylist2, mylist2->next);
    ll = llen(mylist);
    assert(ll == 6);
    assert(lget(mylist2, 1) == 4); // starts with zero
    assert(lget(mylist2, 4) == 7); // starts with zero

    /*when elem lands up at the start*/
    struct node *mylist3 = NULL;
    lpush(&mylist3, 8);
    lpush(&mylist3, 6);
    lpush(&mylist3, 5);
    lpush(&mylist3, 4);
    lpush(&mylist3, 1);
    lpush(&mylist3, 7);

    lsorted_insert(&mylist3, mylist3);
    ll = llen(mylist);
    assert(ll == 6);
    assert(lget(mylist3, 0) == 1); // starts with zero
    assert(lget(mylist3, 4) == 7); // starts with zero

    /*when elem lands up at the start but has to be placed at the end*/
    struct node *mylist4 = NULL;
    lpush(&mylist4, 8);
    lpush(&mylist4, 6);
    lpush(&mylist4, 5);
    lpush(&mylist4, 4);
    lpush(&mylist4, 1);
    lpush(&mylist4, 9);

    lsorted_insert(&mylist4, mylist4);
    ll = llen(mylist);
    assert(ll == 6);
    assert(lget(mylist4, 0) == 1); // starts with zero
    assert(lget(mylist4, 5) == 9); // starts with zero
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
    /*test_insert_sort();*/
    return 0;
}
