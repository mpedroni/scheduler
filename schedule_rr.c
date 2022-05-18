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
    task->quantum = QUANTUM;

    if (head == NULL)
    {
        head = malloc(sizeof(struct node));
        insert(head, task);
        return;
    }

    append(head, task);
}

static int min(a, b)
{
    return a <= b ? a : b;
}

// invoke the scheduler
void schedule()
{
    while (*head != NULL)
    {
        int quantum = (*head)->task->quantum;
        int burst = (*head)->task->burst;
        int slice = min(quantum, burst);

        run((*head)->task, slice);

        (*head)->task->burst -= slice;
        (*head)->task->quantum -= slice;

        if ((*head)->task->burst == 0)
        {
            delete (head, (*head)->task);
            continue;
        }

        if ((*head)->task->quantum == 0)
        {
            (*head)->task->quantum = QUANTUM;
            append_node(head, *head);
        }
    }

    free(head);
}
