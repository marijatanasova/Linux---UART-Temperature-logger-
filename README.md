Linux UART Temperature Logger

A project implemented in C for reading temperature data from an STM32 microcontroller 
via UART serial communication and logging timestamped readings to a file on Linux.

1. Hardware
- STM32F103 microcontroller
- DS18B20 temperature sensor (1-Wire protocol)
- USB to serial connection

2. Build
  make

3. Run
  sudo ./uart_logger

4. Output
  Logs temperature readings with timestamps to uart_temp.log
