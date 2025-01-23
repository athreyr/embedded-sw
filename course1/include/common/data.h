/******************************************************************************
 * Copyright (C) 2025 by Athrey Ranjith Krishnanunni
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of data manipulation operations
 *
 * This header file provides an abstraction of very basic data manipulation
 * operations. 
 *
 * @author Athrey Ranjith Krishnanunni
 * @date 23 Jan 2025
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Converts data from int type to ASCII
 *
 * The number to be converted is passed in as a signed 32-bit integer. Bases 2
 * to 16 are supported. This function returns the length of the converted data
 * (including a negative sign). Example my_itoa(ptr, 1234, 10) returns an ASCII
 * string length of 5 (including the null terminator). This function handles
 * signed data.
 * 
 * @param data Number to be converted into an ASCII string
 * @param ptr Pointer to the address where the string is populated
 * @param base Bases to be used for conversion
 *
 * @return Length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief Converts data from ASCII string to int
 *
 * The character string to be converted is passed in as a pointer, along with 
 * the number of digits in the character set. Bases 2 to 16 are supported. This
 * function returns the converted 32-bit signed integer.
 * 
 * @param ptr Pointer to the address where the string is populated
 * @param digits Number of digits in the character set
 * @param base Bases to be used for conversion
 *
 * @return Length of the converted data
 */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
