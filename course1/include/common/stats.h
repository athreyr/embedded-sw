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
 * @file stats.h 
 * @brief Header file or stats.c, containing only function declarations
 *
 * This file includes declarations and documentation for the functions from the
 * stats.c file, except main. With each declaration, comments are provided with
 * a description of the function, the inputs, and return value.
 *
 * @author Athrey Ranjith Krishnanunni
 * @date 13 Jan 2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */
 
void print_statistics(unsigned char arr[], unsigned int N);
/**
 * @brief Prints statistics and reverse sorts an unsigned 16-bit integer array
 *
 * This function takes as an input a 16-bit integer array. This will print the 
 * minimum and maximum element in the array, along with the mean and median of
 * the data set in the array. All statistics are rounded down to the nearest
 * integer (truncated towards zero). The array passed into it will also be
 * reverse sorted (i.e. 0th element will be the largest, and last one the
 * smallest) in order to calculate the median.
 *
 * @param arr char array whose statistics is to be printed
 * @param N The size of the array
 *
 * @return None
 */

void print_array(unsigned char arr[], unsigned int N);
/**
 * @brief Displays an unsigned 16-bit integer array to screen as a column
 *
 * This function takes as an input a 16-bit integer array. This will print all
 * the elements of the array to screen, separated by newlines, and in single
 * quotations ('1'\n'2' etc.).
 *
 * @param arr char array which is to be printed
 * @param N The size of the array
 *
 * @return None
 */

unsigned char find_median(unsigned char arr[], unsigned int N);
/**
 * @brief Computes median of unsigned 16-bit integer array after sorting it
 *
 * This function takes as an input a 16-bit integer array. This will reverse
 * sort its elements (so that the 0th element in the maximum value in the
 * array), and then computes the median of the sorted array (rounded down to
 * the nearest integer, i.e. truncated towards zero). The array passed into it
 * is changed.
 *
 * @param arr char array whose median is to be calculated (need not be sorted)
 * @param N The size of the array
 *
 * @return The (truncated) median of the elements in the array
 */

unsigned char find_mean(unsigned char arr[], unsigned int N);
/**
 * @brief Computes mean of unsigned 16-bit integer array (truncated towards 0)
 *
 * This function takes as an input a 16-bit integer array. This will compute
 * the mean of its elements (rounded down to the nearest integer).
 *
 * @param arr char array whose mean is to be calculated
 * @param N The size of the array
 *
 * @return The (truncated) mean of the elements in the array
 */

unsigned char find_maximum(unsigned char arr[], unsigned int N);
/**
 * @brief Finds maximum among elements of unsigned 16-bit integer array
 *
 * This function takes as an input a 16-bit integer array. This will find the
 * maximum element among its contents.
 *
 * @param arr char array whose maximum is to be calculated
 * @param N The size of the array
 *
 * @return The maximum among the elements of the array
 */

unsigned char find_minimum(unsigned char arr[], unsigned int N);
/**
 * @brief Finds minimum among elements of unsigned 16-bit integer array
 *
 * This function takes as an input a 16-bit integer array. This will find the
 * minimum element among its contents.
 *
 * @param arr char array whose minimum is to be calculated
 * @param N The size of the array
 *
 * @return The minimum among the elements of the array
 */

void sort_array(unsigned char arr[], unsigned int N);
/**
 * @brief Reverse sort an unsigned 16-bit interger array using insertion sort
 *
 * This function takes as an input a 16-bit integer array. This will use
 * insertion sort to rearrange the elements of the array passed into it such
 * that the 0th element is the largest and the last element is the smallest.
 *
 * @param arr char array which is to be reverse sorted
 * @param N The size of the array
 *
 * @return None
 */

#endif /* __STATS_H__ */
