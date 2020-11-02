// Insertion Sort Program
// Daron Mauricette

#include <stdio.h>

int main()
{ 
  int array[100], no_elements, i, insert, transfer;
  // Variable to hold the array, the number of elements, the element being
  // inserted and the element being transfered

   //printf("Enter number of elements: \n");
  scanf("%d", &no_elements);
  // Print and scan for the number of elements

  //printf("Enter %d elements: \n", no_elements);
  for(i = 0; i < no_elements; i++)
    scanf("%d", &array[i]);
  // Loop through to find the elements of the array

  // Algorithm to sort
  for (i = 1; i <= no_elements - 1; i++)
  {
    insert = i;
    while (insert > 0 && array[insert-1] > array[insert]) // For descending
    {                                                     // order use "<"
      transfer = array[insert];
      array[insert] = array[insert-1];
      array[insert-1] = transfer;
      insert--;
    }// While
  } // For

  for(i = 0; i < no_elements; i++)
    printf("%d ", array[i]);
  printf("\n");
  // Print out the elements

  return 0;

} // Main
  
  
