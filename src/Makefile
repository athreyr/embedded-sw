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

# Name of Main Target executable
BASENAME = c1m2
TARGET = $(BASENAME).out

# Preprocessor flags (choose platform)
CPPFLAGS = -D$(PLATFORM)

# Same C flags for both platforms
COMMONCFLAGS = \
  -Wall \
  -Werror \
  -g \
  -O0 \
  -std=c99

# Same linker flags for both platforms
COMMONLDFLAGS = \
  -Wl,-Map=$(BASENAME).map

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
  CC = gcc
  CFLAGS = $(COMMONCFLAGS)
  LDFLAGS = $(COMMONLDFLAGS)
  SIZETOOL = size
else
  CC = arm-none-eabi-gcc
  SIZETOOL = arm-none-eabi-size
  LDFLAGS = \
    $(COMMONLDFLAGS) \
    -T ../msp432p401r.lds# folder path relative to src
  CFLAGS = \
    $(COMMONCFLAGS) \
    -mcpu=cortex-m4 \
    -mthumb \
    -march=armv7e-m \
    -mfloat-abi=hard \
    -mfpu=fpv4-sp-d16 \
    --specs=nosys.specs
endif

# Preprocessed output from c-implementation files only (not %.h)
%.i: %.c
	$(CC) -E $< $(INCLUDES) $(CPPFLAGS) -o $@

# Assembly output from final executable. This must be defined before the other 
# rule that creates it from c-implementation files, because if there are two
# pattern matches with the same stem length (which probably won't happen here),
# the one earlier in the makefile takes precedence.
# The -m flag is used to provide the architecture used for interpreting the 
# executable, which seems to be i386 for both platforms (for it to work).
# TODO make it generic
$(BASENAME).asm: $(TARGET)
	objdump -m i386 --disassemble $< > $@

# Assembly output from c-implementation files only (not %.h)
%.asm: %.c
	$(CC) -S $< $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -o $@

# Object files for all c files. Also generate dependencies at this stage using
# -MD flag. Using -M -MF outputfilename will not work because -E is implied, so
# there won't be any compilation. Using -MD directly in main target rule won't
# work either, because the outputfilename in that scenario is inferred from the
# argument for -o, which will only have the name of the target, and not for
# each source file. Use of -MT is only to change the name of the target in the
# dependency file, which will be done correctly in this scenario anyway. -MM
# just removes the .h files from the list, which isn't necessary either.
%.o: %.c
	$(CC) -c $< $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -MD -o $@

# Phonys from now
OBJS = $(SOURCES:.c=.o) # to use in compile-all and clean

.PHONY: compile-all
compile-all: $(OBJS) # will use %.o rules

.PHONY: clean
clean:
	rm -f $(BASENAME).map $(OBJS) $(TARGET) *.i *.asm *.d

# Main Target executable
.PHONY: build
build: $(TARGET)

# In the following rule, the recipe has two commands, and they are separated by
# newline. But they will only be recognized as two separate commands if the
# second one actually starts with a tab (not space.) So we should indent as 
# tabs (TODO maybe it will work with pressing a tab even if we are indenting as
# spaces).
$(TARGET): $(OBJS)
	$(CC) $^ $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZETOOL) $@
