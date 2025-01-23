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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Athrey Ranjith Krishnanunni
 * @date 23 Jan 2025
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h> // for uint8_t
#include <stddef.h> // for size_t

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data from source to destination using pointers
 *
 * This function takes two byte pointers (one source and one destination) and a
 * length of bytes to move from the source location to the destination, and 
 * does the operation. In case there is an overlap between some of the source 
 * and destination addresses, copying still occurs without any data corruption.
 *
 * @param src Pointer to source address
 * @param dst Pointer to destination address
 * @param length Length of bytes
 *
 * @return Pointer to destination address
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies data from source to destination using pointers
 *
 * This function takes two byte pointers (one source and one destination) and a
 * length of bytes to copy from the source location to the destination, and 
 * does the operation. In case there is an overlap between some of the source 
 * and destination addresses, copying still occurs, but with possible corruption
 * of data.
 *
 * @param src Pointer to source address
 * @param dst Pointer to destination address
 * @param length Length of bytes
 *
 * @return Pointer to destination address
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets all locations to a given value
 *
 * This function takes a pointer to a source memory location, a length in bytes,
 * and sets all locations of that memory to a given value.
 *
 * @param src Pointer to source address
 * @param length Length of bytes
 * @param value Value to be set
 *
 * @return Pointer to destination address
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets all locations to zero
 *
 * This function takes a pointer to a source memory location, a length in bytes,
 * and sets all locations of that memory to zero.
 *
 * @param src Pointer to source address
 * @param length Length of bytes
 *
 * @return Pointer to source address
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes in a memory location
 *
 * This function takes a pointer to a source memory location, a length in bytes,
 * and reverses the order of all the bytes.
 *
 * @param src Pointer to source address
 * @param length Length of bytes
 *
 * @return Pointer to source address
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates words in dynamic memory
 *
 * This function takes the number of words to allocate in dynamic memory, and
 * returns a pointer to memory if successful, or a Null pointer if not.
 *
 * @param length Length of bytes
 *
 * @return Pointer to address (or Null)
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamic memory allocation
 *
 * This function frees a dynamic memory allocation by providing the pointer.
 *
 * @param src Pointer to the memory location
 *
 * @return void
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
