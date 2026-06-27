#include <stdio.h>
#include "task_node.h"

static const char* TAG = "MAIN";

int main() {
    TaskList_t list = queue_init();
    queue_add_task(&list, "First Task");
    queue_add_task(&list, "Second Task");
    queue_add_task(&list, "Third Task");
    queue_add_task(&list, "Fourth Task");
    
    print_task_queue(list);

    TaskNode_t* node = queue_get_next_task(&list);
    LOG_I(TAG, "%s", node->task_description);

    print_task_queue(list);
    return 0;
}
