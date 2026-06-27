#include "activity_log.h"

const char* TAG = "ACTIVITY_LOG";

HistoryList_t history_list_init(void){
    HistoryList_t list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}
uint8_t history_log_activity(HistoryList_t* list, const char* entry){
    HistoryNode_t* new_node = (HistoryNode_t*)malloc(sizeof(HistoryNode_t));
    if(new_node == NULL) {
        LOG_E(TAG, "Can't allocate Heap memory");
        return 0;
    }
    new_node->prev = NULL;
    new_node->next = list->head; // point to old head
    strncpy(new_node->log_entry, entry, 49);
    new_node->log_entry[49] = '\0';

    if(list->head != NULL){
        list->head->prev = new_node;
    }else{
        list->tail = new_node;
    }
    list->head = new_node;
    LOG_W(TAG, "added new history node!!");
    return 1;
}

void print_history_list(const HistoryList_t* list){
    // check list --> create a temp node --> iterate list
    HistoryNode_t* current_node = list->head;
    int count = 0;
    LOG_I(TAG, "===== The Activity Log =====");
    while(current_node != NULL) {
        LOG_I(TAG, "N.O: %d - %s", count, current_node->log_entry);
        count++;
        current_node = current_node->next;
    }
}

void history_navigate(HistoryList_t* list){
    
}


