/******************************************************************************
 * Copyright (C) 2025 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Analytics on the max, min, mean, median of data set, after ordering
 *
 * This file analyzes an array of unsigned char data items and report analytics
 * on the maximum, minimum, mean, and median of the data set. In addition, the
 * data set is reordered from large to small. All statistics are rounded down
 * to the nearest integer. After analysis and sorting is done, that data is
 * printed to the screen with some formatting.
 *
 * @author Athrey Ranjith Krishnanunni
 * @date 13 Jan 2025
 *
 */
#include "stats.h"

#include "platform.h"

/* Size of the Data Set */
// #define SIZE (40)

/* Add other Implementation File Code Here */

/* void print_statistics(unsigned char *arr, unsigned int N) {
  printf("Minimum is '%u'\n", find_minimum(arr, N));
  printf("Maximum is '%u'\n", find_maximum(arr, N));
  printf("Mean is '%u'\n", find_mean(arr, N));
  printf("Median is '%u'\n", find_median(arr, N));
} */

void print_array(unsigned char arr[], unsigned int N) {
  // Use PRINTF macro function only if VERBOSE flag is defined
#ifdef VERBOSE
  for (int i = 0; i < N; i++) {
    PRINTF("'%u'\n", arr[i]);
  }
#endif
}

unsigned char find_median(unsigned char arr[], unsigned int N) {
  sort_array(arr, N);

  unsigned char mid = 0;
  if (N % 2 != 0) {
    // N is odd
    mid = arr[(N + 1) / 2 - 1];  // (N+1)/2'th value
  } else {
    // N is even
    mid = (arr[N / 2 - 1] + arr[N / 2]) / 2;
    // mean of N/2'th and (N/2+1)'th values
  }

  return mid;
}

unsigned char find_mean(unsigned char arr[], unsigned int N) {
  unsigned int sum = arr[0];  // can't use char, will overflow
  for (int i = 1; i < N; i++) {
    sum += arr[i];
  }
  return (sum / N);
}

unsigned char find_maximum(unsigned char arr[], unsigned int N) {
  unsigned char max = arr[0];
  for (int i = 1; i < N; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char arr[], unsigned int N) {
  unsigned char min = arr[0];
  for (int i = 1; i < N; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

void sort_array(unsigned char arr[], unsigned int N) {
  // insertion sort algorithm
  for (int i = 1; i < N; i++) {
    // save element at this position because its position may be overwritten
    unsigned char max = arr[i];

    // start from the element immediately above it
    int j = i - 1;
    /* j cannot be initialized inside a for loop instead because it has a
    bigger scope (see below) */

    // move elements smaller than max that are above it, one step below
    while (j >= 0 && arr[j] < max) {
      arr[j + 1] = arr[j];
      j--;
    }

    // insert max at the position where the previous loop exited
    arr[j + 1] = max;  // j would have already been decremented before loop exit
  }
}
