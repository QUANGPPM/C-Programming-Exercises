#ifndef ACTIVITY_LOG_H
#define ACTIVITY_LOG_H
#ifdef __cplusplus
extern "C"{
#endif
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // dynamic allocation
#include <string.h>
#include "logger.h"

typedef struct HistoryNode {
    char log_entry[50];
    struct HistoryNode* next;
    struct HistoryNode* prev;
}HistoryNode_t;

typedef struct {
    HistoryNode_t* head;
    HistoryNode_t* tail;
}HistoryList_t;

HistoryList_t history_list_init(void);
uint8_t history_log_activity(HistoryList_t* list, const char* entry);
void print_history_list(const HistoryList_t* list);
void history_navigate(HistoryList_t* list);

#ifdef __cplusplus
}
#endif
#endif