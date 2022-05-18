/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "schedule_rr.c"
#include "task.h"

#define SIZE 100
#define MILISECONDS_PER_MINUTE 1000

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    in = fopen(argv[1], "r");

    time_t begin = clock();

    while (fgets(task, SIZE, in) != NULL)
    {
        temp = strdup(task);
        name = strsep(&temp, ",");
        priority = atoi(strsep(&temp, ","));
        burst = atoi(strsep(&temp, ","));

        // add the task to the scheduler's list of tasks
        add(name, priority, burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();

    double execution_time = (double)(clock() - begin) / CLOCKS_PER_SEC * MILISECONDS_PER_MINUTE;
    printf("\nexecution time: %fms\n", execution_time);

    return 0;
}
