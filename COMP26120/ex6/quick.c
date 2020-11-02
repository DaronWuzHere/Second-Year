// Quick Sort Program
// Daron Mauricette

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX_NO 1000000

void QuickSort(int array[], int min, int max);

// Quick Sort function
void QuickSort(int array[], int min, int max)
{
  int swap_index1, swap_index2, swap, pivot;
  int length = sizeof(array)/sizeof(int);

  if (length <= 1) 		// When the array becomes too small to sort
    return;			// end the recursion

  if(min < max)			// Assigns the indices and the pivot
  {
    pivot = min;
    swap_index1 = min;
    swap_index2 = max;
  
    // This is the algorithm that sorts the
    while(swap_index1 < swap_index2)
    {
      while(array[swap_index1] <= array[pivot] && swap_index1 < max)
        swap_index1++;

      while(array[swap_index2] > array[pivot])
        swap_index2--;

      if(swap_index1 < swap_index2)
      {
        swap = array[swap_index1];
        array[swap_index1] = array[swap_index2];
        array[swap_index2] = swap;
      } // If
    } // While
  
    swap = array[pivot];
    array[pivot] = array[swap_index2];
    array[swap_index2] = swap;

    QuickSort(array, min, (swap_index2 - 1)); 		// Recursive calls that
    QuickSort(array, (swap_index2 + 1), max);		// partiton the array 
  } // If   						// for sorting

} // Quick Sort


// The main function
int main()
{
  int array[MAX_NO] = {0};
  int no_elements, i;
  // Variable to hold the array, the loop counter and the number of elements

  //printf("Enter number of elements: \n");
  scanf("%d", &no_elements);
  // Print and scan for the number of elements

  //printf("Enter %d elements: \n", no_elements);
  for(i = 0; i < no_elements; i++)
    scanf("%d", &array[i]);
  // Loop through to find the elements of the array

  QuickSort(array, 0, (no_elements - 1));
  
  for(i = 0; i < no_elements; i++)
    printf("%d ", array[i]);
  printf("\n");
  // Print out the elements

  return 0;

} // Main
