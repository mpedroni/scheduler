#include <stdio.h>
#include <stdlib.h>

#include "CPU.h"
#include "list.h"
#include "schedulers.h"
#include "task.h"

// add a task to the list
void add(char *name, int priority, int burst)
{
    static int taskId = 1;

    Task *task = malloc(sizeof(Task));
    task->name = name;
    task->priority = priority;
    task->burst = burst;
    task->tid = taskId++;
    task->quantum = -1;

    if (head == NULL)
    {
        head = malloc(sizeof(struct node));
        insert(head, task);
        return;
    }

    append(head, task);
}

// invoke the scheduler
void schedule()
{

    while (*head != NULL)
    {
        if ((*head)->task->quantum == -1)
        {
            (*head)->task->quantum = malloc(sizeof(int));
            (*head)->task->quantum = QUANTUM;
        }

        run((*head)->task, TIME_UNITS_PER_RUN);

        (*head)->task->burst -= TIME_UNITS_PER_RUN;
        (*head)->task->quantum -= TIME_UNITS_PER_RUN;

        if ((*head)->task->burst <= 0)
        {
            delete (head, (*head)->task);
            continue;
        }

        if ((*head)->task->quantum <= 0)
        {
            (*head)->task->quantum = -1;
            append_node(head, *head);
        }
    }

    free(head);
}
