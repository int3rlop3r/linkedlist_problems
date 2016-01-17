#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

struct node* build_new() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

void append(struct node** list, int data) {
    struct node* tmp_node = *list;
    struct node* new_node = malloc(sizeof(struct node));

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

void push(struct node** list, int data) {
    struct node* new_node = malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
}

int insert(struct node** list, int position, int data) {
    struct node* tmp_node = NULL;

    if (position == 0) {
        push(list, data);
        return 0;
    }

    int counter = 1;
    struct node* new_node = malloc(sizeof(struct node));

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

void print_elements(struct node* mylist) {
    struct node* tmp_node = mylist;

    while (tmp_node != NULL) {
        printf("%d ", tmp_node->data);
        tmp_node = tmp_node->next;
    }
    printf("\n");
}

int list_len(struct node* list) {
    struct node* tmp_node = NULL;
    int counter = 0;

    for (tmp_node = list; tmp_node != NULL; tmp_node = tmp_node->next) {
        counter++;
    }

    return counter;
}

int get_data_at(struct node* list, int index) {
    struct node* tmp = list;
    int counter = 0;

    while (list != NULL) {

        if (counter == index)
            return list->data;
        
        counter++;
        list = list->next;
    }

    return -1;
}

