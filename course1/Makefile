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
# This makefile is used to create the complete build targets for two platforms
# (the native HOST and the cross-compiled MSP432). The default is MSP432, which
# can be overriden using the PLATFORM flag. The source files and includes 
# directory are read from sources.mk, which are different for the two platforms.
# 
# Use: make [TARGET] [VERBOSE=TRUE] [MACRO-OVERRIDES] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       c1.out - Final executable
#       build - Same as c1.out
#       clean - Silently removes c1.out from current directory
# 
# Verbosity:
#       VERBOSE=TRUE - Compiles executable with -DVERBOSE flag, which prints 
#                      more information to screen
# 
# Macro Overrides:
#       BASE_10=10 - Value of the BASE_10 macro, not defined in course1.c
#       BASE_16=16 - Value of the BASE_16 macro, not defined in course1.c
# 
# Platform Overrides:
#       PLATFORM=HOST - native compiler, linker (gcc) (default)
#       PLATFORM=MSP432 - cross-compiler, linker (arm-none-eabi-gcc)
#
#------------------------------------------------------------------------------

# Verbosity
VERBOSE = FALSE

# Macro definitions
BASE_10 = 10
BASE_16 = 16

# Platform Overrides
PLATFORM = HOST

include sources.mk # must be after PLATFORM definition for proper SOURCES

# Name of Main Target executable
BASENAME = c1
TARGET = $(BASENAME).out

# Preprocessor flags (choose platform and define macros)
CPPFLAGS = \
  -D$(PLATFORM) \
  -DBASE_10=$(BASE_10) \
  -DBASE_16=$(BASE_16) \
  -DCOURSE1

ifeq ($(VERBOSE),TRUE)
  CPPFLAGS += -DVERBOSE
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
  CC = gcc
  CFLAGS = 
  LDFLAGS = 
else
  CC = arm-none-eabi-gcc
  LDFLAGS = -T msp432p401r.lds
  CFLAGS = \
    -mcpu=cortex-m4 \
    -mthumb \
    -march=armv7e-m \
    -mfloat-abi=hard \
    -mfpu=fpv4-sp-d16 \
    --specs=nosys.specs
endif

$(TARGET): $(SOURCES)
	$(CC) $^ $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@

# Phonys from now
.PHONY: clean
clean:
	rm -f $(TARGET)

# Main Target executable
.PHONY: build
build: $(TARGET)
