#ifndef MAX7219_H
#define MAX7219_H

/* --- MAX7219 Register Addresses --- */
#define MAX7219_REG_NOOP         0x00
#define MAX7219_REG_DIGIT0       0x01 // Row 1
#define MAX7219_REG_DIGIT1       0x02 // Row 2
#define MAX7219_REG_DIGIT2       0x03 // Row 3
#define MAX7219_REG_DIGIT3       0x04 // Row 4
#define MAX7219_REG_DIGIT4       0x05 // Row 5
#define MAX7219_REG_DIGIT5       0x06 // Row 6
#define MAX7219_REG_DIGIT6       0x07 // Row 7
#define MAX7219_REG_DIGIT7       0x08 // Row 8
#define MAX7219_REG_DECODE_MODE  0x09
#define MAX7219_REG_INTENSITY    0x0A
#define MAX7219_REG_SCAN_LIMIT   0x0B
#define MAX7219_REG_SHUTDOWN     0x0C
#define MAX7219_REG_DISPLAY_TEST 0x0F

/* --- MAX7219 Default Data Values --- */
#define MAX7219_MODE_DECODE_OFF  0x00 // Use for 8x8 Matrix (Raw Pixels)
#define MAX7219_MODE_DECODE_ON   0xFF // Use for 7-Segment displays
#define MAX7219_SCAN_ALL         0x07 // Scan all 8 rows
#define MAX7219_SHUTDOWN_OFF     0x01 // Normal operation (Power On)
#define MAX7219_SHUTDOWN_ON      0x00 // Power-saving mode (Power Off)
#define MAX7219_TEST_ON          0x01 // All LEDs On
#define MAX7219_TEST_OFF         0x00 // Normal operation

/*typedef strcutcs*/
typedef struct 
{
    uint8_t DECODE_MODE_config; 
    uint8_t INTENSITY_config; 
    uint8_t SCAN_LIMIT_config; 
    uint8_t SHUTDOWN_config; 
    uint8_t DISPLAY_TEST_config; 
}max7219_config;


/* Function declartion */
void max7219_write( spi_device_handle_t spi, uint8_t reg, uint8_t data); 
void max7219_init( spi_device_handle_t spi, max7219_config * config); 

#endif
