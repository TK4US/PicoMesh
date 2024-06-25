// #define RADIOLIB_CUSTOM_ARDUINO 1
// #define RADIOLIB_TONE_UNSUPPORTED 1
// #define RADIOLIB_SOFTWARE_SERIAL_UNSUPPORTED 1

#define ARDUINO_ARCH_AVR

#ifndef HAS_WIFI
#define HAS_WIFI 1
#endif

#define HAS_GPS 1

#define USE_SSD1306
#define I2C_SDA 4
#define I2C_SCL 5

// Recommended pins for SerialModule:
// txd = 8
// rxd = 9

#define EXT_NOTIFY_OUT 22
#define BUTTON_PIN 17

#define LED_PIN LED_BUILTIN

#define BATTERY_PIN 26
// ratio of voltage divider = 3.0 (R17=200k, R18=100k)
#define ADC_MULTIPLIER 3.1 // 3.0 + a bit for being optimistic
#define BATTERY_SENSE_RESOLUTION_BITS ADC_RESOLUTION

#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS

#define LORA_SCK 10
#define LORA_MISO 12
#define LORA_MOSI 11
#define LORA_CS 3

#define USE_RF95
#define LORA_DIO0 27
#define LORA_DIO1  RADIOLIB_NC
#define LORA_RESET 15
#define LORA_DIO2 2

#define GPS_UBLOX
#define GPS_RX_PIN 21
#define GPS_TX_PIN 20