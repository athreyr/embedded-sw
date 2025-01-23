/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Athrey Ranjith Krishnanunni
 * @date 23 Jan 2025
 *
 */
#include "memory.h"

#include <stdint.h>
#include <stdlib.h> // need for malloc and free
// #include <stddef.h> // included in stdlib anyway

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char *ptr, unsigned int index, char value) {
  ptr[index] = value;
}

void clear_value(char *ptr, unsigned int index) {
  set_value(ptr, index, 0);
}

char get_value(char *ptr, unsigned int index) {
  return ptr[index];
}

void set_all(char *ptr, char value, unsigned int size) {
  unsigned int i;
  for (i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char *ptr, unsigned int size) {
  set_all(ptr, 0, size);
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length) {
  // We don't have to worry about data corruption
  for (uint8_t i = 0; i < length; i++) {
    *(dst + i) = *(src + i);
  }
  return dst;
}

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length) {
  /*
    Since the memory is assumed to be from src to src+length-1 (as opposed to
    src-(length-1) ), data corruption only happens when we are moving to a
    destination in between src and src+length-1. This cannot be universally
    prevented by first copying all the data to a location that is outside,
    e.g. from src+length to src+length+length-1, because destination might be in
    between these new addresses, corrupting the data when populating dst.

    So we need to only copy to a temporary location if there is overlap.
  */

  for (uint8_t i = 0; i < length; i++) {
    if (dst == src + i) {
      // Copy to tmp
      uint8_t *tmp = src + length;
      tmp = my_memcopy(src, tmp, length);

      src = tmp;  // so that copying to dst can be done with only src
      // (can be done in previous line itself, but this way is more readable)

      break;  // no need to check later addresses
    }
  }

  // Now copy to dst
  dst = my_memcopy(src, dst, length);
  return dst;  // not in previous line for readability
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value) {
  for (uint8_t i = 0; i < length; i++) {
    *(src + i) = value;
  }
  return src;
}

uint8_t *my_memzero(uint8_t *src, size_t length) {
  return my_memset(src, length, 0);
}

uint8_t *my_reverse(uint8_t *src, size_t length) {
  /*
    For even length, there are exactly length/2 pairs, so we need to iterate
    from 0 to (length/2-1) to cover them all.
    For odd length, there are (length-1)/2 pairs and one left, so we only need
    to iterate from 0 to (length-1)/2 -1 to cover them all.
    But for odd length, length/2 rounds towards zero, which means it is only
    necessary to iterate from 0 to length/2-1 in either case. (length is
    constrained to be non-negative since it's an unsigned type).
  */
  for (uint8_t i = 0; i < length / 2; i++) {
    uint8_t tmp = *(src + i);
    *(src + i) = *(src + length - 1 - i);
    *(src + length - 1 - i) = tmp;
  }
  return src;
}

int32_t *reserve_words(size_t length) {
  int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));
  return ptr;
}

void free_words(int32_t *src) {
  free((void *)src);
}