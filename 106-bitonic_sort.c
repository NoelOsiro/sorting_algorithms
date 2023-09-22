#include <stdio.h>
#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, 1);
}

/**
 * bitonic_sort_recursive - Recursively performs Bitonic sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    bitonic_sort_recursive(array, mid, 1);
    bitonic_sort_recursive(array + mid, mid, 0);

    bitonic_merge(array, size, dir);
}

/**
 * bitonic_merge - Merges two bitonic sequences
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size < 2)
        return;

    size_t k = size / 2;

    for (size_t i = 0; i < size; i++)
    {
        if ((i < k && array[i] > array[i + k]) == dir)
        {
            swap(&array[i], &array[i + k]);
        }
    }

    bitonic_merge(array, k, dir);
    bitonic_merge(array + k, k, dir);
}

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
