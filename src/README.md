Files
=====
- _commonTypes.h_: typedefs for the Gateway project
- _crc.c/h_: CRC routine for RSI protocol
- _gpio.c/h_: GPIO commands (not used for Eval test)
- _led.c/h_: LED control (not used for Eval test)
- _misc.c/h_: Timer helper functions
- _mod\_rsi.c/h_: RSI module, interface to RSI commands
- _mod\_socket.c/h_: Socket module; IPC between RSI and BLE is domain socket
- _rsi\_commands.c/h_: handlers for specific RSI commands
- _rsiTest.c/h_: Test app to exercise the RSI -> BLE interface
- _serial.c/h_: sets up the UART interface for RS-485 (RSI)
