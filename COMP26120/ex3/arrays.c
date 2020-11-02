#include <stdio.h>
#include "arrays.h"

/* declare your struct for a person here */

typedef struct person {
  char* name;
  int age;
} person;


static void insert(person *people[], char *name, int age, int *nextfreeplace) 
{
  
  /* put name and age into the next free place in the array parameter here */
  people[*nextfreeplace] = malloc(sizeof(person));
  people[*nextfreeplace]->name = name;
  people[*nextfreeplace]->age = age;

  /* modify nextfreeplace here */
  (*nextfreeplace)++;
}

int main(int argc, char *argv[]) 
{
  int nextfreeplace = 0;
  int i;
  /* declare the people array here */
  person *people[HOW_MANY];

  for (i = 0; i < HOW_MANY; i++) 
  {
    insert(people, names[i], ages[i], &nextfreeplace);
  }

  /* print the people array here*/

  for (i = 0; i < HOW_MANY; i++) 
  {
    printf("%d: %s is %d\n", i, names[i], ages[i]);
  }

  for (i = 0; i < HOW_MANY; i++)
  {
    free(people[i]);
  }
  return 0;
 
}
