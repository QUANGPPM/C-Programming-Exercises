#ifndef TASK_NODE_H
#define TASK_NODE_H
#ifdef __cplusplus
extern "C"{
#endif
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // dynamic allocation
#include <string.h>
#include "logger.h"

#define DONE 1
#define ERROR 0

typedef struct TaskNode {
    char task_description[50];
    struct TaskNode* next;
}TaskNode_t;

typedef struct {
    TaskNode_t* head;
    TaskNode_t* tail;
}TaskList_t;

TaskList_t queue_init(void);
uint8_t queue_add_task(TaskList_t* list, char* description);
TaskNode_t* queue_get_next_task(TaskList_t* list);
void print_task_queue(TaskList_t list);


#ifdef __cplusplus
}
#endif
#endif