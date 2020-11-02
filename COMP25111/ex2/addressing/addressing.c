//------------------------------------------------------------------------------
// A template for the first investigation into variables and pointers in C

#include <stdlib.h>		// Libraries which may be needed
#include <stdio.h>

void method_1(int x);		// Take on trust for the moment

int glob_1, glob_2;		// Globally scoped variables

//------------------------------------------------------------------------------

main (int argc, char *argv[]) {	// The 'root' programme; execution start

  int local_1, local_2;		// Variables local to 'main'
  int *ptr_1, *ptr_2;		// More local variables - note '*'
  				// These may be used later

  printf("Memory investigation programme\n");

  glob_1  = 0x12345678;		// Put a distinctive value in a variable
  local_1 = 0xABCDEF;		// ... and again

  printf("Variable glob_1  contains data %08X\n", glob_1);
  printf("Variable local_1 contains data %08X\n", local_1);

  method_1(local_1);		// Call something, with an argument

  printf("That's all folks\n");

  exit(0);
}

//------------------------------------------------------------------------------

void method_1(int arg_1) {	// Declare a function

  int meth_int_1;			// Declare a local variable, in the function

  meth_int_1 = 0xDEADBEEF;	// Another distinctive hex value

  printf("Variable arg_1   contains data %08X\n", arg_1);
  printf("Variable meth_int_1 contains data %08X\n", meth_int_1);

  return;
}

//==============================================================================
