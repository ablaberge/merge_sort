#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int *array, int size);
void createArray(int *array, int arraySize);
void printArray(int *array, int arraySize);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Please input an array size when calling the function. Thank you!\n");
        return 0;
    }

    int arraySize = atoi(argv[1]); // Get user's chosen array size.
    int *array = (int *)malloc(arraySize * sizeof(int));
    createArray(array, arraySize); // Create array of random numbers based on user's chosen size.

    if (!array) // Check that array was successfully allocated to the heap; if not, quit execution.
    {
        fprintf(stderr, "Array could not be opened. Heap space is likely not available for the necessary array.\n");
        return 1;
    }

    if (arraySize <= 100)
    {
        printf("Before: ");
        printArray(array, arraySize);
    }

    mergeSort(array, arraySize);
    if (arraySize <= 100)
    {
        printf("After: ");
        printArray(array, arraySize);
    }

    return 0;
}

/**
 * Fills the given array of a specified size with random integers such
 * that no value is greater than or equal to size.
 *
 * @param array to be filled with random numbers
 * @param size of array to be generated
 *
 *
 **/
void createArray(int *array, int arraySize)
{
    srand(time(NULL)); // Seed rand() with current time so it generates "random" numbers

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = (rand() % arraySize);
    }
}

void printArray(int *array, int arraySize)
{
    printf("{");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("}\n");
}

void mergeSort(int *array, int size)
{
}
