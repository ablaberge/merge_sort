#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void mergeSort(int *array, int size);
int createArray(int size);

int main(int argc, char **argv)
{

    int arraySize = atoi(argv[1]);

    // Create array of random numbers based on user's chosen size.
    int *array = createArray(arraySize);

     // Check that array was successfully allocated to the heap; if not, quit execution.
    if (!array)
    {
        fprintf(stderr, "Array could not be opened. Heap space is likely not available for the necessary array.\n");
        return 1;
    }

        return 0;
}

int createArray(int size)
{
    int *array = (int *)malloc(size * sizeof(int));
   
    srand(time(NULL)); // Seed rand() with current time so it generates "random" numbers

    for (int i = 0; i < size; i++){
        array[i] = (rand() % size);
    }
    return array;
}

void mergeSort(int *array, int size)
{
}
