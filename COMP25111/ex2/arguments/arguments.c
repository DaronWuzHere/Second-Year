// An illustration of command line arguments ...
// ... and more about pointers

#include <stdlib.h>		// Libraries which are needed
#include <stdio.h>

/*----------------------------------------------------------------------------*/

main (int argc, char *argv[])	// The 'root' programme; execution start
{
int ii;

//This is the size of the array of the string.
int sizeOfArray = argc * sizeof(argv);
int sizeOf_argv = sizeof(argv);

//If statement to print according to the amount of arguments.

printf("-_-_-_-_-_-_-_-_-_- Text Output of the Program -_-_-_-_-_-_-_-_-_-_-\n");
if (argc == 1) printf("1 argument supplied\n");
else           printf("%d arguments supplied\n", argc);


printf("The size of the \"argv\" is %d\n", sizeOf_argv);
printf("The number of arguments givem are %d\n", argc);
printf("The size of the array is %d\n", sizeOfArray);
printf("Argument pointer array: %016X\n", argv);



for (ii = 0; ii < argc; ii++)	// Iterate over arguments supplied
  {
  printf("  Pointer %2d at address %016X is %016X", ii, &argv[ii], argv[ii]);
  printf(" to string \"%s\".\n", argv[ii]);
   }

exit(0);
}

/*----------------------------------------------------------------------------*/
