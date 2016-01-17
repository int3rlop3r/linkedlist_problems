#ifndef __LL_H
#define __LL_H

struct node {
    int data;
    struct node* next;
};

struct node* build_new();

void append(struct node** list, int data);

void push(struct node** list, int data);

int insert(struct node** list, int position, int data);

void print_elements(struct node* mylist);

int list_len(struct node* list);

int get_data_at(struct node* list, int index);

#endif

