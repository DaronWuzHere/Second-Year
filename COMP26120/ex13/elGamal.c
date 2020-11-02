// Created by Daron Mauricette, May 2019

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Task 1

unsigned long hcf(unsigned long a, unsigned long b) 
{
  unsigned long r = 0;

  if (b == 0)
    return a;
  else
  { 
    r = a % b;
    return hcf(b, r);   
  } // Else
} // HCF

unsigned long fme(unsigned long g, unsigned long x, unsigned long p)
{
  unsigned long ans = 1; 
  g = g % p;

  while (x > 0)
  {
    if (x & 1)
      ans = (ans * g) % p;

    x = x >> 1;  
    g = (g * g) % p; 
  }
  return ans; 
  
} // FME

/*
The running time of my function is O(log x), because it is to the power of x, 
*/

// Task 4
unsigned long imp(unsigned long y, unsigned long p)
{
  unsigned long x = 0;
  
  int n = hcf(y, p); 
  if (n != 1) 
    return 0; 
  else
  { 
    int x = (x % p + p) % p; 
    return x; 
  } 
  
} // IMP

/*
The running time of this function is O(log y). The call to the fme function is where 
the running time is O(log y) is the reason for this.
*/

// Task 5
int main()
{
  printf("Prime modulus is 65537\n");
  printf("Primitive root wrt 65537 is 3\n");
  printf("Choose: e (encrypt) | d (decrypt) | k (get public key) | x (exit)?\n");

  char reply;
  scanf("%s", reply);
  unsigned long key, secnum, answer;
  switch(reply)
  { 
       case e: printf("Type secret number to send: ");
               scanf("%s", secnum);
               printf("Type public key: ");
               scanf("%s", answer);
	       dl
               break; 
       case d:  
               break; 
       case k: printf("Type private key: ");
               scanf("%s", key);
               answer = fme(3, key, 65537);
               printf("Public key is: %f\n", answer);
               break;
       case x: return 0;
               break; 
       default:return 0;
               break;   
   } 
   return 0; 
} // Main
