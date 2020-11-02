// Merge Sort Program
// Daron Mauricette

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX_NO 1000000


void MergeSort(int array[], int min, int max);
void Merge(int array[], int a1_index, int m1_index, int a2_index, int m2_index);
 
// Initiates the merge sort with the min and max
void MergeSort(int array[], int min, int max)
{
  int mid;
        
  if(min < max)
  {
    mid = (min + max) / 2;
    MergeSort(array , min, mid);        		
    MergeSort(array, mid+1, max);    		
    Merge(array, min, mid, mid+1, max);    	
  }  // If
}
 

// Function that contains the algorithm to perform the merge sort
void Merge(int array[], int a1_index, int m1_index, int a2_index, int m2_index)
{
  int i, n, k;  		// Variable to assist in the loops
  i = a1_index;     		// Array indices
  n = a2_index;    
  k = 0;
  int *merge = NULL;		// Create the array that performs the merge
  merge = calloc(m2_index, (2 * sizeof(array)));  
  

  // Algorithms that perform that merge sort
  while(i <= m1_index && n <= m2_index)   	 
  {
    if(array[i] < array[n])
      merge[k++] = array[i++];
    else
      merge[k++] = array[n++];
  } // While
    
  while(i <= m1_index)
    merge[k++] = array[i++];

  while(n <= m2_index)    
    merge[k++] = array[n++];
        
  for(i = a1_index, n = 0; i <= m2_index; i++, n++) 	// Fill the orignal
    array[i] = merge[n]; 				// array back up

} // Merge


// Main function of the program
int main()
{
  int array[MAX_NO] = {0};		// Variable to hold the array, 
  int no_elements, i;  			// the loop counter and 
					// the number of elements
  
  //printf("Enter number of elements: \n");	// Print and scan for 
  scanf("%d", &no_elements);               	// the number of elements
  

  //printf("Enter %d elements: \n", no_elements); // Loop through to find the
  for(i = 0; i < no_elements; i++)	 	// elements of the array
    scanf("%d", &array[i]);
  

  MergeSort(array, 0, (no_elements - 1));
  for(i = 0; i < no_elements; i++)		// Print out the elements
    printf("%d ", array[i]);
  printf("\n");

  return 0;
} // Main
