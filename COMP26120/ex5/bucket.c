// Bucket Sort Program
// Daron Mauricette

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX_NO 32768

void Bucket(int array[], int no_elements)
{
  int i, k;
  int *buckets = NULL;
 
    int max = array[0]+1;
    for (i = 1; i < no_elements; i++)
    {
        if (max < (array[i]+1))
            max = array[i]+1;
    } // For
    // Find the largest element in the array

    buckets = calloc(max, sizeof(*buckets));
    // Allocate and zero-fill a proper-sized array
 
    for(i=0; i < no_elements; i++)
    {
        (buckets[array[i]])++;
    }
 
    for(i=0, k=0; i < max; i++)
    {
        for(; buckets[i] > 0; (buckets[i])--)
            array[k++] = i;
    }// For
 
    free(buckets);
}// Bucket

int main()
{
  int array[MAX_NO] = {0};
  int no_elements, i;
  // Variable to hold the array, the loop counter and the number of elements

 // printf("Enter number of elements: \n");
  scanf("%d", &no_elements);
  // Print and scan for the number of elements

 // printf("Enter %d elements: \n", no_elements);
  for(i = 0; i < no_elements; i++)
    scanf("%d", &array[i]);
  // Loop through to find the elements of the array

  Bucket(array, no_elements);
  for(i = 0; i < no_elements; i++)
    printf("%d ", array[i]);
  printf("\n");
  // Print out the elements

  return 0;

} // Main
