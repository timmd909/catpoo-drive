# ARDUINO_LIBS = AccelStepper QueueArray Wire SoftwareSerial
ARDUINO_LIBS = AccelStepper
BOARD_TAG = leonardo
MONITOR_PORT = /dev/ttyACM0
# MONITOR_PORT = /dev/arduino
MONITOR_BAUDRATE = 57600
AVRDUDE_ARD_BAUDRATE = 57600
# VARIANT = leonardo
# VARIANT = mega
MCU = atmega32u4

USER_LIB_PATH := $(realpath ./lib)

include /usr/share/arduino/Arduino.mk
