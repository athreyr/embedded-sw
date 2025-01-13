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



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned int N = SIZE;

  /* Statistics and Printing Functions Go Here */
  printf("Here is the input array:\n");
  print_array(test, N);

  printf("Here is the sorted array:\n");
  sort_array(test, N);
  print_array(test, N);

  printf("Here are the statistics:\n");
  print_statistics(test, N);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char * arr, unsigned int N) {

printf("Minimum is '%u'\n", find_minimum(arr, N));
printf("Maximum is '%u'\n", find_maximum(arr, N));
printf("Mean is '%u'\n", find_mean(arr, N));
printf("Median is '%u'\n", find_median(arr, N));

}

void print_array(unsigned char arr[], unsigned int N) {

  for (int i = 0; i < N; i++) {
    printf("'%u'\n", arr[i]);
  }

}

unsigned char find_median(unsigned char arr[], unsigned int N) {

  sort_array(arr, N);

  unsigned char mid = 0;
  if ( N % 2 != 0 ) { // if N is odd
    mid = arr[(N+1)/2 - 1]; // (N+1)/2'th value
  }
  else { // N is even
    mid = ( arr[N/2-1] + arr[N/2] ) / 2; // mean of N/2'th and (N/2+1)'th values
  }

  return mid;

}

unsigned char find_mean(unsigned char arr[], unsigned int N) {

  unsigned int sum = arr[0];
  for (int i = 1; i < N; i++) {
    sum += arr[i];
  }
  return (sum/N);

}

unsigned char find_maximum(unsigned char arr[], unsigned int N) {

  unsigned char max = arr[0];
  for (int i = 1; i < N; i++) {
    if ( arr[i] > max ) {
      max = arr[i];
    }
  }
  return max;

}

unsigned char find_minimum(unsigned char arr[], unsigned int N) {

  unsigned char min = arr[0];
  for (int i = 1; i < N; i++) {
    if ( arr[i] < min ) {
      min = arr[i];
    }
  }
  return min;

}

void sort_array(unsigned char arr[], unsigned int N) {

  for (int i = 1; i < N; i++) {

    unsigned char max = arr[i];
    int j = i - 1; /* can't put in for loop
    because bigger scope (see below) */

    while ( j >= 0 && arr[j] < max) {
      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = max;

  }

}

