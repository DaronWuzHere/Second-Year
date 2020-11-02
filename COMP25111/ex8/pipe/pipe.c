// A template for 'piping' between processes

#include <stdlib.h>		// Libraries which are needed
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


main (int argc, char *argv[])	// The 'root' programme; execution start
{
pid_t new_PID;			// PID return value from fork
int   pipefd[2];		// Pipe ends identifier from call

printf("Hello from '%s'\n", argv[0]);// My name

pipe(pipefd);			// Create a pipe; record 'handles'

new_PID = fork();		// Split into two processes

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if (new_PID != 0)

  {					// Parent process: transmitter
  int bytes_written;
  char *message = "Hello World!";	// Traditional message :-)

  sleep(1);				// Let child get ahead

  printf("Parent to send message\n");

  bytes_written = write(pipefd[1], message, strlen(message) + 1);
			// The " + 1" is to include the string terminator

  printf("Bytes written: %d\n", bytes_written);
  }

else

  {					// Child process: receiver
  char buffer[20];			// Somewhere to put the input
  int  bytes_read;

  printf("    Child waiting for message\n");

  bytes_read = read(pipefd[0], buffer, 20);// Read from pipe into "buffer"

  if (bytes_read == -1) printf("    Error: %d\n", errno);
  else                { printf("    Bytes read: %d\n", bytes_read);
                        printf("    Received string: %s\n", buffer); }

  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

printf("Goodbye from process %d\n", getpid());

exit(0);			// A way of stopping this process
				// The '0' indicates "okay"
}

//------------------------------------------------------------------------------
