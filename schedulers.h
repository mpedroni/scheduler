#include <stdlib.h>

#include "list.h"

struct node **head;

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#define TIME_UNITS_PER_RUN 10

// add a task to the list
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();
