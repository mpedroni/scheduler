#include <stdio.h>
#include <stdlib.h>

#include "CPU.h"
#include "list.h"
#include "schedulers.h"
#include "task.h"

void add(char *name, int priority, int burst)
{
    static int taskId = 1;

    Task *task = malloc(sizeof(Task));
    task->name = name;
    task->priority = priority;
    task->burst = burst;
    task->tid = taskId++;

    if (head == NULL)
    {
        head = malloc(sizeof(struct node));
        insert(head, task);
        return;
    }

    struct node *temp = *head;
    while (temp != NULL)
    {
        if (task->burst < temp->task->burst)
        {
            insert_before(head, task, temp);
            return;
        }
        temp = temp->next;
    }

    append(head, task);
}

void schedule()
{
    struct node *temp;
    struct node *node = *head;
    while (node != NULL)
    {
        run(node->task, TIME_UNITS_PER_RUN);
        node->task->burst -= TIME_UNITS_PER_RUN;

        if (node->task->burst == 0)
        {
            temp = node;
            node = node->next;
            free(temp->task);
            free(temp);
        }
    }

    free(head);
}