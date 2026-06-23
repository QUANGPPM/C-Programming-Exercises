#include "global_config.h"
#include "config_manager.h"
int main(){
    DriveConfig* config = NULL;
    const char* filepath = "/home/quangppm/C-Assigments/App/config_file/config.txt";
    load_config(filepath, &config);
    config->current_limit = 5.0;
    sync_config(config);
    return 0;
}