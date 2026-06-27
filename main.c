#include <stdio.h>
#include "task_node.h"
#include "activity_log.h"

static const char* TAG = "MAIN";

int main() {
    // linked list
    TaskList_t list = queue_init();
    HistoryList_t h_list = history_list_init();

    queue_add_task(&list, "First Task");
    history_log_activity(&h_list, "Added: First task");
    queue_add_task(&list, "Second Task");
    history_log_activity(&h_list, "Added: Second task");
    queue_add_task(&list, "Third Task");
    history_log_activity(&h_list, "Added: Third task");
    queue_add_task(&list, "Fourth Task");
    history_log_activity(&h_list, "Added: Fourth task");
    
    print_task_queue(list);
    print_history_list(&h_list);
    TaskNode_t* node = queue_get_next_task(&list);
    LOG_I(TAG, "%s", node->task_description);
    print_task_queue(list);

    // Doubly linked list
    
    return 0;
}
