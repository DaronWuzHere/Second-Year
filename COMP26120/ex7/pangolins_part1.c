// A program that plays a guessing game with the user called "panglolins".
// Created by Daron Mauricette

#include <stdio.h>
#include <string.h>

// Step 1A
struct node {
  // Object name
  char *object;
  
  // Question 
  char *question; 

  struct node *yes_ptr;
  struct node *no_ptr;
};

// Step 1B
void nodePrint(struct node *print) {


  printf("Object: %s\n", print->object);
  printf("Question: %s\n", print->question);

} // Node Print


void treePrint(struct node *print) {
    if (print != NULL) {
      nodePrint(print);
      treePrint(print->yes_ptr);
      treePrint(print->no_ptr);
    } // If
  } // Tree Print
    
int main() {
  struct node *root = malloc(sizeof(struct node));
  struct node *node2 = malloc(sizeof(struct node));
  struct node *node3 = malloc(sizeof(struct node));
  struct node *node4 = malloc(sizeof(struct node));
  struct node *node5 = malloc(sizeof(struct node));
  struct node *node6 = malloc(sizeof(struct node));
  struct node *node7 = malloc(sizeof(struct node));
  struct node *node8 = malloc(sizeof(struct node));
  struct node *node9 = malloc(sizeof(struct node));

  root->question = "Is it round?\n";
  root->object = "pangolin";
  root->yes_ptr = node2;
  root->no_ptr = node5;

  node2->question = "Is it edible?\n";
  node2->object = NULL;
  node2->yes_ptr = node3;
  node2->no_ptr = node4;

  node3->question = "Is it from Italy?\n" ;
  node3->object = "a pizza";
  node3->yes_ptr = NULL;
  node3->no_ptr = NULL;

  node4->question = "Is it an endangered animal?\n";
  node4->object = "a pangolin";
  node4->yes_ptr = NULL;
  node4->no_ptr = NULL;

  node5->question = "Is it soft?\n";
  node5->object = NULL;
  node5->yes_ptr = node6;
  node5->no_ptr = node7;

  node6->question = "Can you sleep on it?\n";
  node6->object = NULL;
  node6->yes_ptr = node8;
  node6->no_ptr = node9;

  node7->question = "Is it from the earth?\n";
  node7->object = "a rock";
  node7->yes_ptr = NULL;
  node7->no_ptr = NULL;

  node8->question = "Is it from you bed?\n";
  node8->object = "a pillow";
  node8->yes_ptr = NULL;
  node8->no_ptr = NULL;
       
  node9->question = "Is it made in an oven?\n";
  node9->object = "bread";
  node9->yes_ptr = NULL;
  node9->no_ptr = NULL; 
  treePrint(root);
   
  free(root);
  free(node2);
  free(node3);
  free(node4);
  free(node5);
  free(node6);
  free(node7);
  free(node8);
  free(node9);

} // Main
