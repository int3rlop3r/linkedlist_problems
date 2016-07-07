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
    struct node *dummy_node;

    while(*list != NULL) {
        dummy_node = (*list)->next;
        free(*list);
        *list = dummy_node;
    }
}

/* pops an element off the list */
int lpop(struct node **list) {
    int data = (*list)->data;
    struct node *tmp = (*list)->next;
    free(*list);
    *list = tmp;

    return data;
}

/*an ordered insert*/
void lsorted_insert(struct node **list, struct node *elem) {
    struct node *tmp_list;
    struct node *prev_node = NULL;
    struct node *elem_prev_node = NULL;
    int elem_prev_set = 0;
    int sorted = 0;

    /*if the element was at the head*/
    if (*list == elem) {
        *list = (*list)->next;
        elem_prev_set = 1;
    }

    for(tmp_list = *list; tmp_list != NULL; tmp_list = tmp_list->next) {

        if (elem == tmp_list)
            elem_prev_set = 1;

        if (!elem_prev_set)
            elem_prev_node = tmp_list;

        if (elem->data < tmp_list->data) {
            if (elem_prev_node != NULL)
                elem_prev_node->next = elem_prev_node->next->next;

            prev_node->next = elem;
            elem->next = tmp_list;
            sorted = 1;
        }

        prev_node = tmp_list;
    }

    /*if element was the largest on in the list*/
    if (!sorted) {
        if (elem_prev_node != NULL)
            elem_prev_node->next = elem_prev_node->next->next;
        prev_node->next = elem;
        elem->next = NULL;
    }
}

