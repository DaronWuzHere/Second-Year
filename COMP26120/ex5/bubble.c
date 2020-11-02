// Bubble Sort Program in C
// Daron Mauricette

#include <stdio.h>
#define MAX_NO 32768
int main()
{
  int array[MAX_NO], no_elements, swap, i, c;
  // Array to hold the elements, variable to hold the number of elements.
  // Variable to hold the element being swapped 
  // and the first and second loop count.

  //printf("Enter number of elements: \n");
  scanf("%d", &no_elements);
  // Print and scan for the number of elements

 // printf("Enter %d elements: \n", no_elements);
  for(i = 0; i < no_elements; i++)
    scanf("%d", &array[i]);
  // Loop through to find the elements of the array
 
  for(i = 0; i < (no_elements - 1); i++)
  {
    for(c = 0; c < (no_elements - 1); c++)
    {
      if(array[c] > array[c+1])		// For descending order use "<"
      {
        swap = array[c];
        array[c] = array[c+1];
        array[c+1] = swap;
      } // If
    } // For
  } // For
  // The algorithm that performs the bubble sort

  for(i = 0; i < no_elements; i++)
    printf("%d ", array[i]);
  printf("\n");
  // Print out the elements

  return 0;

} // Main
  
