#include <stdio.h>
#include "data.h"

/* declare your struct for a person here */

typedef struct person {
  char* name;
  int age;
  struct person* next;
}person;

static *people insert_start(person *people, char *name, int age, int *nextfreeplace) 
{
  
  /* put name and age into the next free place in the array parameter here */
  person * newPerson; 
  newPerson = (person*)malloc(sizeof(struct person));
  newPerson->name = name;
  newPerson->age = age;
  newPerson->next = *people;
  *people = newPerson;
  return *people;

  /* modify nextfreeplace here */
  (*nextfreeplace)++;
}

static *people insert_end(person *people, char *name, int age, int *nextfreeplace) 
{
  person* newPerson; 
  /* put name and age into the next free place in the array parameter here */
  newPerson = (person*)malloc(sizeof(struct person));
  newPerson->name = name;
  newPerson->age = age;
  if (people == NULL){
    newPerson->next = *people;
    *people = newPerson;
    return *people;
  }
  else 
    person * current = people
    while (current == NULL)

  /* modify nextfreeplace here */
  (*nextfreeplace)++;
}

int main(int argc, char *argv[]) 
{
  int nextfreeplace = 0;
  int i;
  /* declare the people array here */
  struct person* people = NULL;

  for (i = 0; i < HOW_MANY; i++) 
  {
    (insert_start(people, names[i], ages[i], &nextfreeplace) = *people;
  }

  /* print the people array here*/

  for (i = 0; i < HOW_MANY; i++) 
  {
    printf("%d: %s is %d\n", i, names[i], ages[i]);
  }

  for (i = 0; i < HOW_MANY; i++)
  {
    free(people);
  }
  return 0;
 
}
