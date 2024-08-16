# weather_station_stm32

For the Arm Mbed Enabled NUCLEO-L031K6 Board, the target STM32 is STM32L031K6T6

Trying a basic blynk sketch:

User LD3: the green LED is a user LED connected to Arduino Nano signal D13
corresponding to the STM32 I/O PB3 (pin 26).

• When the I/O is HIGH value, the LED is on
• When the I/O is LOW, the LED is off

Ensure that your platformio.ini file is set up correctly:

[env:nucleo_l031k6]
platform = ststm32
board = nucleo_l031k6
framework = arduino

Build and upload the sketch to the Nucleo-L031K6 board:
pio run --target upload


### Table 9. Arduino Nano connectors on NUCLEO-F031K6

| Connector | Pin number | Pin name | STM32 pin | Function |
|----------|----------|----------|----------|----------|
|  CN3| 1 | D1 | PA9 | USART1_TX (1) |
|  | 2| D0 | PA10 | USART1_RX (1) |
|  | 3 | RESET | NRST | RESET |
|  | 4 | GND | - | ground |
|  | 5 | D2 | PA2 | - |
|  | 6 | D3 | PA7 | TIM3_CH3 |
|  | 7 | D4 (5) | PA6 | - |
|  | 8 | D5 (5) | PA5 | TIM16_CH1N (2) |
|  | 9 | D6 | PA4 | TIM14_CH1 |
|  | 10 | D7 (3) | PA3 | - |
|  | 11 | D8 (3)| PA1 | - |
|  | 12 | D9 | PA0 | TIM1_CH1 |
|  | 13 | D10 | - | SPI_CS (4) || TIM1_CH4 |
|  | 14 | D11 | - | SPI_MOSI || TIM3_CH2 |
|  | 15 | D12 | PB3 | SPI1_SCK |
|  |  |  |  |  |

| Connector | Pin number | Pin name | STM32 pin | Function |
|----------|----------|----------|----------|----------|
|  CN4| 1 | VIN | - | Power input |
|  | 2| GND | - | Ground |
|  | 3 | RESET | NRST | RESET |
|  | 4 | +5V | - | 5V input / output |
|  | 5 | A7 | PA2 | ADC_IN2 |
|  | 6 | A6 | PA7 | ADC_IN7 |
|  | 7 | A5 (5) | PA6 | ADC_IN6 || I2C1_SCL |
|  | 8 | A4 (5) | PA5 | ADC_IN5 || I2C1_DA |
|  | 9 | A3 | PA4 | ADC_IN4 |
|  | 10 | A2 | PA3 | ADC_IN3 |
|  | 11 | A1 | PA1 | ADC_IN1 |
|  | 12 | A0 | PA0 | ADC_IN0 |
|  | 13 | AREF | - | Row 13 Col 5 |
|  | 14 | +3V3 | - | Row 14 Col 5 |
|  | 15 | D13 | PB3 | SPI1_SCK |
|  |  |  |  |  |

1. Only one USART is available and it is shared between Arduino Nano and VCP. The selection is done by
remapping (no need to change the hardware configuration).
2. D5 PWM on inverted channel Timer 16.
3. D7/D8 shared with OSC_IN/OSC_OUT.
4. SPI_CS is made by GPIO.
5. Limitations on A4 and A5, D4 and D5, related to I2C configuration, are explained in Section 6.10: Solder
bridges according to SB16/SB18 setting.