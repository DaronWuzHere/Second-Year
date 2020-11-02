// Edited by Daron Mauricette, January 29th, 2019
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define __USE_BSD
#include <string.h>

#include "speller.h"
#include "dict.h"

typedef struct node *tree_ptr;
struct node 
{
  Key_Type element; // only data is the key itself
  tree_ptr left, right;
  // add anything else that you need
};

struct table 
{
  tree_ptr head; // points to the head of the tree
  Key_Type element; // only data is the key itself
  tree_ptr current; // used for traversal of the tree
  tree_ptr previous;// to keep track to the previous node
};

Table initialize_table(/*ignore parameter*/) 
{
  // Initialize left and right to NULL but initialize the key element
  tree_ptr head = malloc(sizeof(struct node));
  head->element = 0;
  head->left = NULL;  
  head->right = NULL;
} // Initialize_Table


Table insert(Key_Type newElement, Table newNode) 
{
  tree_ptr current = newNode;
  if (newElement < current->element) 
  {
    current->left = insert(newElement, current->left);
    current->element = newElement;
  }
  else if (newElement > current->element)
  {
    current->right = insert(newElement, current->right);
    current->element = newElement;
  }

  return current;
} // Insert


Boolean find(Key_Type newElement, Table node) 
{
  tree_ptr current = node;
  if (newElement < current->element) 
  {
    find(newElement, current->left);
    current->element = newElement;
    return true;
  }
  else if (newElement > current->element)
  {
    find(newElement, current->right);
    current->element = newElement;
    return true;
  }
  else
    return false;

} // Find

void print_table(Table node) 
{
  tree_ptr current = node;

  if (current->left != NULL)
    print_table(current->left);
  else 
    printf("%s\n", current->element);
  // Print the left side of the tree

  if (current->right != NULL)
    print_table(current->right);
  else
    printf("%s\n", current->element);
  // Print the right side of the tree
} // Print_Table

void print_stats (Table node) 
{
  int leftDepth = 0 ;
  int rightDepth = 0;

  if (node == NULL)
    printf(0);
  else
  {
    tree_ptr current = node;
    // Compute the depth
    
    print_stats(current->left);
    print_stats(current->right);

    // Use the longer depth
    if (leftDepth > rightDepth)
      printf("%d\n", leftDepth);
    else
      printf("%d\n", rightDepth);
  }
} // Print_Stats

void tidy(Table node)
{
  tree_ptr current = node;
  if (current->left != NULL)
    tidy(current->left);
  else
    free(current);
  if (current->right != NULL)
    tidy(current->right);
  else
    free(current);
}  // Tidy

    
