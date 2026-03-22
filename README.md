# MAX7219-LED-Matrix
A custom component for the 8 by 8 LED matrix driven by the MAX1792x IC  for ESP32-IDF


---

# MAX7219 ESP-IDF Component

A simple professional, modular SPI driver for the **MAX7219 LED Matrix Driver**. This version uses a stateless design, allowing a single driver to manage multiple matrices by passing specific SPI handles to each function.

## 🚀 Features
* **Stateless Architecture:** No global variables; functions require an `spi_device_handle_t`.
* **Multi-Device Support:** Easily control multiple 8x8 matrices (e.g., Left Eye, Right Eye) using the same code logic.
* **Struct-Based Configuration:** Centralized setup for Decode Mode, Intensity, and Scan Limits.
---

## 📁 Component Structure
```text
max7219/
├── include/
│   └── max7219.h      <-- Definitions, Registry Map, and Config Struct
├── max7219.c          <-- SPI logic and Register writing
└── CMakeLists.txt     <-- Build instructions
```

---

## 🛠️ Usage Guide

### 1. Define Configuration
Set your display parameters using the `max7219_config` struct:

```c
max7219_config matrix_cfg = {
    .DECODE_MODE_config = MAX7219_MODE_DECODE_OFF, // Raw pixels for faces
    .INTENSITY_config   = 0x01,                   // Dim (0x00) to Bright (0x0F)
    .SCAN_LIMIT_config  = MAX7219_SCAN_ALL,       // Use all 8 rows
    .SHUTDOWN_config    = MAX7219_SHUTDOWN_OFF    // Power On
};
```

### 2. Initialization
After adding your device to the SPI bus and obtaining a handle (`spi_device_handle_t`), initialize the chip:

```c
// Pass the SPI handle and the pointer to your config
max7219_init(spi_handle, &matrix_cfg);
```

### 3. Writing to Registers
The `max7219_write` function is the core of the driver. It sends a 16-bit packet (Address + Data) over the specified SPI handle.

```c
// Example: Manually changing intensity on the fly
max7219_write(spi_handle, MAX7219_REG_INTENSITY, 0x08);
```

---

## 📑 Function Prototypes

### `max7219_init`
```c
void max7219_init(spi_device_handle_t spi, max7219_config *config);
```
Initializes the MAX7219 with the provided configuration and clears the display buffer.

### `max7219_write`
```c
void max7219_write(spi_device_handle_t spi, uint8_t reg, uint8_t data);
```
Sends a raw command to a specific register.


```

---
