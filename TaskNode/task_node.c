#include "task_node.h"
static const char* TAG = "TASK_NODE";

TaskList_t queue_init(){
    TaskList_t list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

uint8_t queue_add_task(TaskList_t* list, char* description){
    // create a node --> assign description --> return result
    TaskNode_t* new_node = (TaskNode_t*)malloc(sizeof(TaskNode_t));
    if (new_node == NULL) {
        LOG_E(TAG, "Can't allocate Heap memory");
        return ERROR;
    }
    strncpy(new_node->task_description, description, 49);
    new_node->task_description[49] = '\0';
    new_node->next = NULL;  // so important
    // assign
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    LOG_I(TAG, "added new node!!");
    return DONE;


}
TaskNode_t* queue_get_next_task(TaskList_t* list){
    if (list->head == NULL) {
        LOG_W(TAG, "Empty list");
        return NULL;
    }
    TaskNode_t* current_node = list->head;
    list->head = current_node->next;
    LOG_I(TAG, "get node successfully!!");
    return current_node;
}

void print_task_queue(TaskList_t list){
    TaskNode_t* current_node = list.head;
    int count = 0;
    while(current_node != NULL) {
        LOG_I(TAG, "N.O: %d - %s", count, current_node->task_description);
        count++;
        current_node = current_node->next;
    }
}
