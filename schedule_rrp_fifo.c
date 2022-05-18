#include<string.h>
#include<stdlib.h>

#include "schedulers.h"
#include "task.h"
#include "CPU.h"
#include "list.h"

struct node *tasks[MAX_PRIORITY + 1];
struct node *nextNode;

void add(char *name, int priority, int burst) {

    Task *t = malloc(sizeof(Task));
    t->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(t->name, name);

    t->priority = priority;
    t->burst = burst;
    t->remaining = burst;

    insert(&tasks[priority], t);
}


Task *nextTask(struct node *tl) {

    Task *nextTask = nextNode->task;
    nextNode = (nextNode->next) ? nextNode->next : tl;

    return nextTask;
}

void schedule() {

    for(size_t p = MIN_PRIORITY; p <= MAX_PRIORITY; p++) {
        nextNode = tasks[p];
        while(tasks[p]) {
            Task *t = nextTask(tasks[p]);
            int slice = QUANTUM < t->remaining ? QUANTUM : t->remaining;
            run(t, slice);
            t->remaining -= slice;

            if(t->remaining <= 0) {
                delete(&tasks[p], t);
            }
        }
    }
}