#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define __USE_BSD
#include <string.h>

#include "speller.h"
#include "dict.h"

typedef struct 
{ // hash-table entry
  Key_Type element; // only data is the key itself
  enum {empty, in_use, deleted} state;
} cell;

typedef unsigned int Table_size; // type for size-of or index-into hash table

struct table 
{
  cell *cells; Table_size table_size; // cell cells [table_size];
  Table_size num_entries; // number of cells in_use
  // add anything else that you need
};

Table initialize_table (Table_size size) 
{
  struct Table hashArray[size] = malloc(sizeof(struct table));
}

Table insert (Key_Type element, Table key) 
{
  struct 
}

Boolean find (Key_Type element, Table key) 
{
}

void print_table (Table table) 
{
}

void print_stats (Table table) 
{
}
