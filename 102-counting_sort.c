#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 Counting sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int *counting_array, *output_array;
    int max = 0;
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    counting_array = malloc(sizeof(int) * (max + 1));
    if (counting_array == NULL)
        return;

    output_array = malloc(sizeof(int) * size);
    if (output_array == NULL)
    {
        free(counting_array);
        return;
    }

    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    for (i = 1; i <= (size_t)max; i++)
        counting_array[i] += counting_array[i - 1];

    print_array(counting_array, max + 1);

    for (i = 0; i < size; i++)
    {
        output_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    free(counting_array);
    free(output_array);
}
