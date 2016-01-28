#ifndef __LL_H
#define __LL_H

struct node {
    int data;
    struct node *next;
};

struct node *build_new();

void lappend(struct node **list, int data);

void lpush(struct node **list, int data);

int linsert(struct node **list, int position, int data);

void lprint(struct node *mylist);

int llen(struct node *list);

int lget(struct node *list, int index);

int lcount(struct node *head, int needle);

void ldelete(struct node **list);

int lpop(struct node **list);

#endif

