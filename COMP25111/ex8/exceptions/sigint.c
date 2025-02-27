//------------------------------------------------------------------------------
// A simplified demonstration of signal handling; part 1

#include <stdlib.h>			// Libraries which may be needed
#include <stdio.h>
#include <signal.h>

struct sigaction sigaction_structure;	// A data structure, filled in below

void goodbye();				// Declaration only - definition below

//------------------------------------------------------------------------------

int num;					// A global variable

//------------------------------------------------------------------------------

int main (int argc, char *argv[])	// The 'root' programme; execution start
{
  
  // Set three fields in a predefined 'struct'
  sigaction_structure.sa_handler = &goodbye;	// Pointer to a -function-
  sigemptyset(&sigaction_structure.sa_mask);	// Call defines 'empty' field
  sigaction_structure.sa_flags   = 0;		// No flags

  // Link the structure to signal "SIGINT" (as generated by ^C)
  sigaction(SIGINT, &sigaction_structure, NULL); // Link
  

  num = 0;

  while (1) num++;			// Everlasting loop!
}

//------------------------------------------------------------------------------

void goodbye(int signum)
{
  printf("\nGoodbye at count %d\n", num);

  exit(1);
}

//------------------------------------------------------------------------------
