# Motor Control Simulation Project

This project is a simple motor control simulator written in C. It models a 32-bit hardware status register and uses a finite state machine to manage motor behavior.

## Key Features

- Simulates a 32-bit status register using a global variable.
- Implements a software FSM with states such as `STATE_INIT`, `STATE_IDLE`, `STATE_RUNNING`, and `STATE_FAULT`.
- Provides motor control commands to start, stop, set faults, and clear faults.
- Uses inline helper logic for hardware status and ADC conversion.

## Project Structure

- `main.c`: program entry point and main control loop.
- `Motor/motor.h` and `Motor/motor.c`: motor control logic and state machine implementation.
- `global_config.h`: shared hardware configuration, status register masks, and utility functions.
- `hardware.c`: simulated hardware register and delay helper.
- `Logger/`: simple logging utilities.

## Usage

The program runs a loop and reads user commands to simulate motor operations, then updates the motor state and logs the result.

