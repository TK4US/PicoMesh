// #define RADIOLIB_CUSTOM_ARDUINO 1
// #define RADIOLIB_TONE_UNSUPPORTED 1
// #define RADIOLIB_SOFTWARE_SERIAL_UNSUPPORTED 1

#define ARDUINO_ARCH_AVR

#define USE_SSD1306

// default I2C pins:
// SDA = 4
// SCL = 5

// Recommended pins for SerialModule:
// txd = 8
// rxd = 9

// #define EXT_NOTIFY_OUT 22
// #define BUTTON_PIN 17

// #define LED_PIN PIN_LED

// #define BATTERY_PIN 26
//  ratio of voltage divider = 3.0 (R17=200k, R18=100k)
#define ADC_MULTIPLIER 3.1 // 3.0 + a bit for being optimistic

#define USE_RF95

#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS

#define LORA_SCK 14
#define LORA_MISO 8
#define LORA_MOSI 15
#define LORA_CS 7

#define LORA_RESET 26
#define LORA_DIO0 27
#define LORA_DIO1 29
#define LORA_DIO2 RADIOLIB_NC
#define LORA_DIO3 RADIOLIB_NC
