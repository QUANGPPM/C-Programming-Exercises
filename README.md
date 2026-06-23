# BKDrive Config Manager

A small C project for practicing packed structs, variadic logging, memory-mapped config files, and syscall error handling.

## Requirements

- Define a packed `Drive_Config` struct:
  - `float current_limit`
  - `float velocity_limit`
  - `int pole_pairs`
  - `uint8_t is_calibrated`
  - total size must be exactly `13` bytes.

- Implement `load_config(const char* filepath, Drive_Config* config_ptr)`:
  - open or create the binary config file
  - ensure file size is `sizeof(Drive_Config)`
  - mmap the file and return the mapped address through `config_ptr`

- Implement `sync_config(Drive_Config* config_ptr)` using `msync()` to flush changes.

- Implement logging with levels `DEBUG`, `INFO`, `WARN`, `ERROR`, `FATAL`.
  - use `snprintf()` and variadic arguments
  - format: `[YYYY-MM-DD HH:MM:SS] [LEVEL] message`

- Check all syscall results (`open`, `ftruncate`, `mmap`, etc.). On error:
  - use `errno` and `strerror()`
  - log as `FATAL`
  - exit with `EXIT_FAILURE`
