#include "driver/spi_master.h"
#include<string.h>
#include"max7219.h" 

// Function to send a command to MAX7219
void max7219_write(, spi_device_handle_t spi, uint8_t reg, uint8_t data) {
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    uint8_t tx_data[2] = {reg, data};
    t.length = 16;
    t.tx_buffer = tx_data;
    spi_device_polling_transmit(spi, &t);
}

void max7219_init(,spi_device_handle_t spi, max7219_config *config) {
    // 1. Wake up the chip using the value stored in the config struct
    max7219_write(MAX7219_REG_SHUTDOWN, config->SHUTDOWN_config, spi);
    
    // 2. Set Decode Mode
    max7219_write(MAX7219_REG_DECODE_MODE, config->DECODE_MODE_config, spi);
    
    // 3. Set Scan Limit
    max7219_write(MAX7219_REG_SCAN_LIMIT, config->SCAN_LIMIT_config, spi);
    
    // 4. Set Intensity
    max7219_write(MAX7219_REG_INTENSITY, config->INTENSITY_config,spi); 
    
    // Clear the display
    for (int i = 1; i <= 8; i++) {
        max7219_write(i, 0x00, spi);
    }
}
