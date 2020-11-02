// An introduction to malloc() and free()

#include <stdlib.h>		// Libraries which may be needed
#include <stdio.h>

//------------------------------------------------------------------------------
// ** Code starts here **

main (int argc, char *argv[])	// The 'root' programme; execution start
{
char *pString;			// Create a pointer to a character
				// (... or, later a -string- of characters.)

pString = malloc(10);		// Get 10 bytes of memory
pString[0] = 'H';
pString[1] = 'e';
pString[2] = 'l';
pString[3] = 'l';
pString[4] = 'o';
pString[5] = '\0';		// Remember a string terminator

printf("%s\n", pString);	// Print the string + a line-feed

*(pString+1) = 'a';		// Another way of manipulating the address
				//  and dereferencing the pointer

printf("%s\n", pString);	// Print the string + a line-feed

free(pString);			// Give the memory back

exit(0);			// ... and relax.

}

//==============================================================================
