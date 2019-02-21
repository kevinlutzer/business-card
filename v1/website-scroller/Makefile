# Author: Kevin Lutzer
# Date: February 21 2017
# Description: Makefile for sumobot api tester

# set build target
TARGET= main.hex

# config stuff
ARCH=attiny45
CPU=1000000UL

# tools
CC=avr-g++
OBJ_CREATOR=avr-objcopy
PROG=avrdude

# directories
BIN_DIR=bin
HEX_DIR=hex

# files
TEST_FILE=main
API_FILE=../business-card-api/charlie_plexing

# flags
AVR_FLAGS=-Os -DF_CPU=$(CPU) -mmcu=$(ARCH)
HEX_FLAGS=-O ihex
PROG_FLAGS=-c avrisp2 -p t45

# all
all: $(HEX_DIR)/$(TEST_FILE).hex

# create dirs
dirs:
	@mkdir -p $(BIN_DIR) $(HEX_DIR)

#recipe to create object files
$(BIN_DIR)/$(TEST_FILE): $(TEST_FILE).cpp $(API_FILE).cpp
	$(CC) $(AVR_FLAGS) -o $@ $^

# create hex file
$(HEX_DIR)/$(TEST_FILE).hex:	$(BIN_DIR)/$(TEST_FILE)
	$(OBJ_CREATOR) $(HEX_FLAGS) -R .eeprom $^ $@

program: $(HEX_DIR)/$(TEST_FILE).hex
	$(PROG) $(PROG_FLAGS) -U flash:w:$(HEX_DIR)/$(TEST_FILE).hex

clean:
	@rm -rf $(BIN_DIR)/$(TEST_FILE).* $(HEX_DIR)/$(TEST_FILE).*
