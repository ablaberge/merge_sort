#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Written by: Annika Laberge
    Date: 13 September 2024

    This program is an implementation of mergesort in C. Merge sort is a divide-and-conquer algorithm 
    that splits an array into smaller subarrays, sorts each one, and then merges them back together to 
    form a sorted array. It operates with a time complexity of O(nlogn). 

    When called, this program expects an integrer input representing array size from the terminal. 
    The program then creates an array of random integers of the specified size. Any element n of the array
    will be such that 0 <= n < size. 

    This array of random numbers will then be sorted. If size of the array is less than or equal to 100,
    the array will be printed before and after sorting.
*/


void mergeSort(int *array, int size);
void merge(int *array, int *aux, int low, int high, int mid);
void sort(int *array, int *aux, int low, int high);
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

/*
 * Function:  createArray
 * --------------------
 * Fills the given array of a specified size with random integers such
 * that no value is greater than or equal to size.
 *
 *  array: the array to be filled with random numbers
 *  arraySize: the size of array to be generated
 *
 */

void createArray(int *array, int arraySize)
{
    srand(time(NULL)); // Seed rand() with current time so it generates "random" numbers

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = (rand() % arraySize);
    }
}

/*
 * Function:  printArray
 * --------------------
 * Prints the given array to the terminal.
 *
 *  array: the array to be printed
 *  arraySize: the size of array
 *
 */
void printArray(int *array, int arraySize)
{
    printf("{");
    for (int i = 0; i < arraySize; i++)
    {
        if (i == arraySize - 1)
            printf("%d", array[i]);

        else
            printf("%d, ", array[i]);
    }
    printf("}\n");
}

/*
 * Function:  mergeSort
 * --------------------
 * "Driver" function of this merge sort implementation.
 * Creates auxillary array to be used throughout the sort and merge, as
 * well as calling the sort function.
 *
 *  array: the array to be sorted
 *  arraySize: the size of array
 *
 */
void mergeSort(int *array, int size)
{
    int *aux = (int *)malloc(size * sizeof(int)); // allocate space from the heap for the auxillary array
    sort(array, aux, 0, (size - 1)); // call sort on the entire array
}

/*
 * Function:  sort
 * --------------------
 * Recursively sorts the given array by splitting it in half
 * until the base case is reached. Finally, merge is called on the
 * array in order to merge the two sorted halves.
 *
 *  array: the array to be sorted
 *  aux: the auxillary array to be used as temporary storage while merging
 *  low: the index of the first element in the array
 *      (after initial function call, this becomes the index of the first element in the active region)
 *  high: the index of the last element in the array
 *      (after initial function call, this becomes the index of the last element in the active region)
 *
 */
void sort(int *array, int *aux, int low, int high)
{
    if (high <= low)                    // if the low index has surpassed or equals the high index, base case has been reached
        return;
    int mid = low + (high - low) / 2;   // calculate midpoint
    sort(array, aux, low, mid);         // sort left half 
    sort(array, aux, mid + 1, high);    // sort right half
    merge(array, aux, low, high, mid);  // merge sorted halves
}

/*
 * Function:  merge
 * --------------------
 * Merges the two sorted halves of the given array; this produces the final sorted array.
 *
 *  array: the array containing the two halves to be merged
 *  aux: the auxillary array to be used as temporary storage while merging
 *  low: the index of the first element in the array
 *  high: the index of the last element in the array
 *  mid: the index of the midpoint of the array
 *
 */
void merge(int *array, int *aux, int low, int high, int mid)
{

    for (int i = low; i <= high; i++)   // copy all elems to the auxillary array
    {
        aux[i] = array[i];
    }

    int a = low;     // create a seperate variable to increment low pointer
    int b = mid + 1; // points to the first element of the second half of array; to be incremented in for loop
    for (int i = low; i <= high; i++)
    {
        if (a > mid)               /* if all elems of first half have been added, 
                                      add remaining elems of the second half  */ 
            array[i] = aux[b++];

        else if (b > high)          /* if all elems of second half have been added, 
                                      add remaining elems of the first half  */ 
            array[i] = aux[a++];

        else if (aux[b] < aux[a])  /* if the first unmerged elem of the second half is less than the 
                                      corresponding elem in the first half, add the elem from the second half  */ 
            array[i] = aux[b++];
            
        else                       /* if the first unmerged elem of the second half is less than the  
                                      corresponding elem in the first half, add the elem from the second half  */ 
            array[i] = aux[a++];
    }
}
