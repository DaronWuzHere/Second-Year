// Created by Daron Mauricette, May 2019

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


// Task 3

unsigned long dl(unsigned long y, unsigned long g, unsigned long p)
{
  unsigned long x = 1;
  while (x < p && y != fme(g, x, p))
  {
    x++;
  } // While
  if (x >= p)
    return 0;
  else
    return x;
} // DL
/*
Modulo exponentiation can be regarded as a one way function because it is simple
to calculate but very difficult to unvers because there are a range of answers
that are applicable to solve to discrete logartithm.
*/
