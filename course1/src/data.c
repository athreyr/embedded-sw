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
// #include <stdio.h>
// #include <stdlib.h>

#include "memory.h"

/* void main() {
  int32_t data = -123;
  uint8_t *ptr;
  ptr = (uint8_t *)malloc(10 * sizeof(int32_t));
  // *ptr = (char)1;
  // *(ptr + 1) = (char)2;
  // *(ptr + 2) = (char)3;
  // printf("%s", ptr);

  uint8_t foo = my_itoa(data, ptr, 10);
  printf("%i\n", foo);

  printf("%s", ptr);
  // for (int i = 0; i < foo; i++) {
  //   printf("%i", *(ptr + i));
  // }
  printf("\n");
} */

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
  if (data < 0) {
    *ptr = '-';
    data = -data;
  } else {
    *ptr = '\0';
  }
  // data is non-negative now
  // uint32_t q = 0;  // quotient, rounds towards zero
  uint8_t i = 1;
  do {
    // *(ptr + i) = num2ascii(data % base);
    *(ptr + i) = data % base;
    data = data / base;
    i++;
  } while (data > 0);

  if (*ptr == '-') {
    *ptr = '\0';
    *(ptr + i++) = '-';
  }
  ptr = my_reverse(ptr, i);
  return i;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
  /* uint8_ t i = 0;
  uint8_t numDigits = digits;
  if (*ptr == '-') {
    numDigits -= 1;
    i = 1;
  }  */
  int32_t result = 0;
  uint32_t power = 1;
  for (uint8_t i = digits - 2; i > 0; i--) {  // digits-1 is \0
    result += *(ptr + i) * power;
    power *= base;
  }

  if (*ptr == '-') {
    return -result;
  } else {
    return (result + *ptr * power);
  }
}

/* uint8_t num2ascii(uint8_t num) {
  uint8_t ascii = '0';
  if (num < 10) {
    ascii += num;
  }
  else {
    num = num - 10;
    ascii = 'A';
    ascii += num;
  }
  return ascii;
} */