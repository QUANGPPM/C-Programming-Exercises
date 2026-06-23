#define _POSIX_C_SOURCE 200809L
#include "config_manager.h"
const char* TAG = "CONFIG MANAGER";
int load_config(const char* filepath, DriveConfig** config_ptr){
    // open file
    int fd_file = open(filepath, O_RDWR | O_CREAT, 0644);
    if(fd_file < 0){
        LOG_E(TAG, "Can't load config, Detailed: %s", strerror(errno));
        return -1;
    }

    // get info of file
    struct stat st;
    if(stat(filepath, &st) == -1){
        perror("get stat");
        LOG_E(TAG, "Can't get info of file, Detailed: %s", strerror(errno));
        close(fd_file);
        return -1;
    }


    // if create new file or file too small => expand file's size to fit DriveConfig
    if (st.st_size < sizeof(DriveConfig)){
        if(ftruncate(fd_file, sizeof(DriveConfig)) == -1){
            LOG_E(TAG, "Can't resize config file, Detailed: %s", strerror(errno));
            close(fd_file);
            return -1;
        }
    }

    // mapping into RAM
    void *map = mmap(NULL, sizeof(DriveConfig), PROT_READ | PROT_WRITE, MAP_SHARED, fd_file, 0);
    if (map == MAP_FAILED){
        LOG_E(TAG, "Can't mapping into RAM, Detailed: %s", strerror(errno));
        close(fd_file);
        return -1;
    }
    *config_ptr = (DriveConfig*)map;
    LOG_I(TAG, "read struct: \n"
                "current limit: %0.2f\n"
                "velocity limit: %0.2f\n"
                "pole pairs: %d\n"
                "is_calibrated: %d\n", 
                (*config_ptr)->current_limit, 
                (*config_ptr)->velocity_limit, 
                (*config_ptr)->pole_pairs, 
                (*config_ptr)->is_calibrated);
    close(fd_file);
    return 0;
}

void sync_config(DriveConfig* config_ptr){
    //check pointer
    if (config_ptr == NULL){
        LOG_E(TAG, "No config pointer");
    }
    //sync
    if (msync(config_ptr, sizeof(DriveConfig), MS_SYNC) == -1){
        LOG_E(TAG, "Failed to sync config to disk");
    } else {
        LOG_I(TAG, "Config synced to disk successfully");
    }

}