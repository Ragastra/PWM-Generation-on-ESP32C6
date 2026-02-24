# 3-Phase SPWM Generation on ESP32-C6 (By Rausheen Khurana)

This project implements a **3-Phase Sinusoidal Pulse Width Modulation (SPWM)** generator using the ESP32-C6 microcontroller. It is designed to drive 3-phase inverters or motors by generating precise PWM signals with a 120° phase shift between them.

## Overview

The code utilizes the ESP32's `ledc` peripheral to generate PWM signals. A pre-calculated sine wave lookup table is used to modulate the duty cycle of the PWM signals to approximate a sinusoidal waveform on the output.

## Features

- **3-Phase Output**: Generates three signals (Phase A, B, and C) offset by 120°.
- **Lookup Table Driven**: Uses a 36-point sine wave lookup table for efficient signal generation.
- **Configurable Parameters**:
  - **Carrier Frequency**: 1 kHz
  - **Resolution**: 8-bit (0-255)
  - **Output Frequency**: Controlled by the loop delay.

## Pin Configuration

| Signal  | ESP32-C6 GPIO Pin |
|---------|-------------------|
| Phase A | GPIO 18           |
| Phase B | GPIO 19           |
| Phase C | GPIO 21           |

## Code Description

The core logic resides in `esp32c6pwmgeneration.ino`. 
1. **Setup**: Configures the 3 pins using `ledcAttach` with the specified frequency and resolution.
2. **Loop**: Continuously iterates through the `sine_table` array.
   - **Phase A**: Reads value at index `i`.
   - **Phase B**: Reads value at index `(i + 12) % 36` (120° shift).
   - **Phase C**: Reads value at index `(i + 24) % 36` (240° shift).
   - Updates the duty cycle for all 3 pins.
   - Waits for 10ms (`delay(10)`) before the next step, determining the speed of the sine wave.

## Requirements

- ESP32-C6 Development Board
- Arduino IDE with ESP32 Board Support Package
