#include <gtest/gtest.h>
#include <cstdio>
#include <sys/stat.h>

extern "C" {
#include "ConfigManager/config_manager.h"
#include "App/global_config.h"
}

TEST(ProjectTest, LoadConfigCreatesAndMapsFile) {
    const char* path = "/home/quangppm/C-Assigments/App/config_file/config.txt";
    DriveConfig *cfg = nullptr;

    int result = load_config(path, &cfg);
    EXPECT_EQ(result, 0);
    ASSERT_NE(cfg, nullptr);

    // File should be mapped and accessible.
    EXPECT_EQ(cfg->pole_pairs, 0);
    EXPECT_EQ(cfg->is_calibrated, 0);

    // Clean up
    munmap(cfg, sizeof(DriveConfig));
    remove(path);
}
TEST(ProjectTest, ModifyConfigAndSynchronize){
    const char* path = "/home/quangppm/C-Assigments/App/config_file/config.txt";
    // load config --> modify --> sync --> deallocate mapping --> load config --> check --> clean up
    DriveConfig* ptr = nullptr; 
    int result = load_config(path, &ptr);
    EXPECT_EQ(result, 0);
    ASSERT_NE(ptr, nullptr);

    // modify
    ptr->current_limit = 1.0;
    ptr->pole_pairs = 7;
    sync_config(ptr);

    // deallocate
    munmap(ptr, sizeof(DriveConfig));
    ptr = nullptr;

    // load config
    result = load_config(path, &ptr);
    EXPECT_EQ(result, 0);
    ASSERT_NE(ptr, nullptr);

    // check
    EXPECT_EQ(ptr->current_limit, 1.0);
    EXPECT_EQ(ptr->pole_pairs, 7);

    //clean up
    munmap(ptr, sizeof(DriveConfig));
    remove(path);
}

TEST(ProjectTest, PermissionDeniedOnReadOnlyFile) {
    const char* path = "/home/quangppm/C-Assigments/App/config_file/config.txt";
    DriveConfig* ptr = nullptr;

    // Ensure file exists and has valid size.
    int result = load_config(path, &ptr);
    EXPECT_EQ(result, 0);
    ASSERT_NE(ptr, nullptr);
    munmap(ptr, sizeof(DriveConfig));

    // Make the file read-only.
    EXPECT_EQ(chmod(path, S_IRUSR | S_IRGRP | S_IROTH), 0);

    // Attempt to open and map read/write.
    result = load_config(path, &ptr);
    EXPECT_NE(result, 0);

    // Restore permissions and cleanup.
    EXPECT_EQ(chmod(path, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH), 0);
    remove(path);
}
