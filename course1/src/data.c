/******************************************************************************
 * Copyright (C) 2025 by Athrey Ranjith Krishnanunni
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Implementation of data manipulation operations
 *
 * This implementation file performs basic data manipulation operations.
 *
 * @author Athrey Ranjith Krishnanunni
 * @date 23 Jan 2025
 *
 */
#include "data.h"

#include <stdint.h>

#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
  if (data < 0) {
    *ptr = '-';
    data = -data;
  } else {
    *ptr = '\0';
  }
  // data is non-negative now
  
  uint8_t i = 1;
  do {
    *(ptr + i++) = data % base; //i'th digit from last, excluding null terminator
    data = data / base;
  } while (data > 0);

  // If data was originally negative, suffix with a negative sign and replace 
  // first element with null terminator
  if (*ptr == '-') {
    *ptr = '\0';
    *(ptr + i++) = '-';
  }

  // Now reverse the string so that null terminator is last (i is the number of
  // digits, including null terminator and negative sign)
  ptr = my_reverse(ptr, i);
  return i;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
  int32_t result = 0;
  uint32_t power = 1;
  for (uint8_t i = digits - 2; i > 0; i--) {  // i=digits-1 is \0, i=0 could just be negative sign
    result += *(ptr + i) * power;
    power *= base;
  }

  // Check if i=0 is negative sign, which means result has to be made negative
  if (*ptr == '-') {
    return -result;
  } else {
    // One more digit is left, should be raised to power and added
    return (result + *ptr * power);
  }
}
