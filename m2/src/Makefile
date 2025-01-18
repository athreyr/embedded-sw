#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

BASENAME = c1m2
TARGET = $(BASENAME).out

CPPFLAGs = \
  -D$(PLATFORM)

COMMONCFLAGS := \
  -Wall \
  -Werror \
  -g \
  -O0 \
  -std=c99

COMMONLDFLAGS = \
  -Wl,-Map=$(BASENAME).map \
  -MD 

# Compiler Flags and Defines
ifeq ( $(PLATFORM), HOST )
  CC = gcc
  CFLAGS = $(COMMONCFLAGS)
  LDFLAGS = $(COMMONLDFLAGS)
else
  CC = arm-none-eabi-gcc
  #LD = 
  LDFLAGS = \
    $(COMMONLDFLAGS) \
    -T msp432p401r.lds
# Architectures Specific Flags
  CFLAGS = \
     $(COMMONCFLAGS) \
	-mcpu=cortex-m4 \
	-mthumb \
    -march=armv7e-m \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16 \
	--specs=nosys.specs
endif

#LD = 


%.i: %.c
	$(CC) -E $< $(INCLUDES) $(CPPFLAGS) -o $@

%.asm: %.i
	$(CC) -S $^ $(INCLUDES) $(CPPFLAGS) $(CFLAGS)
	objdump --disassemble %.s > $@
	make build

%.o: %.c
	$(CC) -c $< $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -o $@

OBJS = $(SOURCES:.c=.o)

.PHONY: clean
clean:
	rm -f $(BASENAME).map $(OBJS) $(TARGET) *.i *.asm *.d

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) -c $^ $(CFLAGS)

# Main Target executable
.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

