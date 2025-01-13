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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */
 
void print_statistics(unsigned char * arr, unsigned int N);
/**
 * @brief Print min, max, mean, median 
 *
 * A function that prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 * @param arr Pointer to the array whose statistics is to be printed
 * @param N The size of the array
 *
 * @return None
 */

void print_array(unsigned char * arr, unsigned int N);
/**
 * @brief Display array to screen
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param arr Pointer to the array which is to be printed
 * @param N The size of the array
 *
 * @return None
 */

unsigned char find_median(unsigned char * arr, unsigned int N);
/**
 * @brief Find median of array
 *
 * Calculates the median of the elements of the input array
 *
 * @param arr Pointer to the array whose median is to be calculated
 * @param N The size of the array
 *
 * @return The median of the elements in the array
 */

unsigned char find_mean(unsigned char * arr, unsigned int N);
/**
 * @brief Find mean of array
 *
 * Calculates the mean of the elements of the input array
 *
 * @param arr Pointer to the array whose mean is to be calculated
 * @param N The size of the array
 *
 * @return The mean of the elements in the array
 */

unsigned char find_maximum(unsigned char * arr, unsigned int N);
/**
 * @brief Find maximum among array
 *
 * Calculates the maximum among the elements of the input array
 *
 * @param arr Pointer to the array whose maximum is to be calculated
 * @param N The size of the array
 *
 * @return The maximum among the elements of the array
 */

unsigned char find_minimum(unsigned char * arr, unsigned int N);
/**
 * @brief Find minimum among array
 *
 * Calculates the minimum among the elements of the input array
 *
 * @param arr Pointer to the array whose minimum is to be calculated
 * @param N The size of the array
 *
 * @return The minimum among the elements of the array
 */

void sort_array(unsigned char * arr, unsigned int N);
/**
 * @brief Sort input array from largest to smallest
 *
 * Sorts the input array (in reverse order)
 *
 * @param arr Pointer to the array which is to be sorted
 * @param N The size of the array
 *
 * @return None
 */

#endif /* __STATS_H__ */
