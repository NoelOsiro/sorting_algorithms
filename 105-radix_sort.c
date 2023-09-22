#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using LSD Radix sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum number to know the number of digits */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Do counting sort for every digit, starting from the least significant digit */
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}

/**
 * counting_sort - Sorts the array based on a significant digit
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current exponent (significant digit)
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    /* Count the occurrences of each digit */
    for (size_t i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    /* Calculate cumulative count */
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    /* Build the output array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to the original array */
    for (size_t i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(output);
}
