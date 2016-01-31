#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

/* creates a basic linked list with default values */
struct node *build_new() {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

/* appends a values to a linked list */
void lappend(struct node **list, int data) {
    struct node *tmp_node = *list;
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;

    if (tmp_node == NULL) {
        *list = new_node;
    } else {

        while (tmp_node->next != NULL) {
            tmp_node = tmp_node->next;
        }
    }

    tmp_node->next = new_node;
}

/* pushes a value onto a linked list */
void lpush(struct node **list, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
}

/* inserts a value at the specified position of
 * the linked list */
int linsert(struct node **list, int position, int data) {
    struct node *tmp_node = NULL;

    if (list == NULL && position == 0) {
        tmp_node = *list;
        tmp_node = (struct node *) malloc(sizeof(struct node));
        tmp_node->data = data;
        tmp_node->next = NULL;
        return 0;
    } else if (position == 0) {
        lpush(list, data);
        return 0;
    }

    int counter = 1;
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    for (tmp_node = *list; tmp_node != NULL; tmp_node = tmp_node->next, counter++) {
        if (counter == position) {
            new_node->data = data;
            new_node->next = tmp_node->next;
            tmp_node->next = new_node;
            return 0;
        }
    }

    return -1;
}

/* print out all the elements of the linked list */
void lprint(struct node *mylist) {
    struct node *tmp_node = mylist;

    while (tmp_node != NULL) {
        printf("%d ", tmp_node->data);
        tmp_node = tmp_node->next;
    }
    printf("\n");
}

/* get the length of the list */
int llen(struct node *list) {
    struct node *tmp_node = NULL;
    int counter = 0;

    for (tmp_node = list; tmp_node != NULL; tmp_node = tmp_node->next) {
        counter++;
    }

    return counter;
}

/* get the count of occurences of 'needle' */
int lcount(struct node *head, int needle) {
    int counter = 0;
    while (head != NULL) {
        if (head->data == needle)
            counter++;
        head = head->next;
    }
    
    return counter;
}

/* get data at the specified position */
int lget(struct node *list, int index) {
    struct node *tmp = list;
    int counter = 0;

    while (tmp != NULL) {
        if (counter == index)
            return tmp->data;

        counter++;
        tmp = tmp->next;
    }

    return -1;
}

/* deletes the entire linked list */
void ldelete(struct node **list) {
    struct node *tmp_list = *list;
    struct node *dummy_node;

    while (tmp_list != NULL) {
        dummy_node = tmp_list;
        tmp_list = tmp_list->next;
        free(dummy_node->next);
        dummy_node->next = NULL;
    }

    /* free up the head */
    free(*list);
    *list = NULL;
}

/* pops an element off the list */
int lpop(struct node **list) {
    struct node *tmp_list = *list;
    int data = tmp_list->data;
    *list = tmp_list->next;
    free(tmp_list);

    return data;
}
