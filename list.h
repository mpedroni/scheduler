/**
 * list data structure containing the tasks in the system
 */
#ifndef LIST_H_
#define LIST_H_

#include "task.h"

struct node
{
    Task *task;
    struct node *next;
};

// insert and delete operations.
void insert(struct node **head, Task *task);
void insert_before(struct node **head, Task *task, struct node *node);
void append(struct node **head, Task *task);
void delete (struct node **head, Task *task);
void traverse(struct node *head);

#endif