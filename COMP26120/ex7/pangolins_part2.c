// A program that plays a guessing game with the user called "panglolins".
// Created by Daron Mauricette
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Creation of the struct that works as a node off a binary tree.
struct node {
  // Object name
  char *object;
  
  // Question 
  char *question; 

  struct node *yes_ptr;
  struct node *no_ptr;
};



// Function that prints one node.
void nodePrint(struct node *print) {
  printf("Object: %s\n", print->object);
  printf("Question: %s\n", print->question);

} // Node Print


// Fucntion that prints the entire tree.
void treePrint(struct node *print) {
    if (print != NULL) {
      nodePrint(print);
      treePrint(print->yes_ptr);
      treePrint(print->no_ptr);
    } // If
  } // Tree Print



// Fucntion that frees the entire tree from memory.
void freeTree(struct node *tree) {
    if (tree != NULL) {
      freeTree(tree->yes_ptr);
      freeTree(tree->no_ptr);
      free(tree);
    } // If
    else
      free(tree);
  } // Tree Print



// Function to print text depending on whether the response was a yes or no.
void YesNoResponse(char *answer){
  if (strcmp(answer, "Yes\n") == 0 | strcmp(answer, "yes\n") == 0){
    printf("Good, that was so easy!\n");
  } // If

  if (strcmp(answer, "No\n") == 0 | strcmp(answer, "no\n") == 0){
    printf("Fine you win.\n");
  } // If
} //YesNoResponse



// Function to return 0 or 1 depending on whether the response was a yes or no.
int YesNoBoolean(char *answer){
  if (strcmp(answer, "Yes\n") == 0 | strcmp(answer, "yes\n") == 0){
    return 1;
  } // If

  if (strcmp(answer, "No\n") == 0 | strcmp(answer, "no\n") == 0){
    return 0;
  } // If
} //YesNoResponse


    
int main(void) {
  int size = 81;
  char *response = malloc(size * sizeof(char*));
  int game = 1;
  struct node *root = malloc(sizeof(struct node));
  struct node *node2 = malloc(sizeof(struct node));
  struct node *node3 = malloc(sizeof(struct node));
  struct node *node4 = malloc(sizeof(struct node));
  struct node *node5 = malloc(sizeof(struct node));
  struct node *node6 = malloc(sizeof(struct node));
  struct node *node7 = malloc(sizeof(struct node));
  struct node *node8 = malloc(sizeof(struct node));
  struct node *node9 = malloc(sizeof(struct node));
  struct node *current = malloc(sizeof(root));

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

  current->question = root->question;
  current->object = root->object;
  current->yes_ptr = root->yes_ptr;
  current->no_ptr = root->no_ptr;

  // Initialise the game.
  printf("Welcome, please think of something.\n");
  printf("%s", root->question);
  fgets(response, size, stdin); 

  if (YesNoBoolean(response)) {
    printf("Is it a %s?\n", root->object);
    *response = NULL;
    fgets(response, size, stdin); 
    if (YesNoBoolean(response))
      YesNoResponse(response);
    else
      YesNoResponse(response);

  } // If
  else 
    YesNoResponse(response);
  
  // Ask to play again
  printf("Would you like to play again?\n");
  fgets(response, size, stdin);

  if (YesNoBoolean(response)){ 
    printf("Okay, please think of something.\n");

    while (game) {
      if (current->yes_ptr == NULL & current->no_ptr == NULL){
        *response = NULL;

        
        if (YesNoBoolean(response)){
          printf("Is it %s?\n", current->object);
          fgets(response, size, stdin); 
          
          YesNoResponse(response);
          if (YesNoBoolean(response)){
 	    // Ask to play again
 	    printf("Would you like to play again?\n");
  	    fgets(response, size, stdin);

              if (!YesNoBoolean(response)){
                game = 0;
	      } // If
              else {
                free(current);
		struct node *current = malloc(sizeof(root));
  	        current->question = root->question;
  		current->object = root->object;
  		current->yes_ptr = root->yes_ptr;
  		current->no_ptr = root->no_ptr;
    	     } // Else
          } // If
          else {
	    // Create the new node
   	    struct node *newNode = malloc(sizeof(struct node));
	    char *newObject = malloc(81 * sizeof(char*)); 
 	    char *newQuestion = malloc(81 * sizeof(char*));

            printf("What were you thinking of?\n");
           
            fgets(newObject, size, stdin);
	    strtok(newObject, "\n");

            printf("What is a question that I can ask about %s, %s",
                  newObject, "beginning with \"Is it\"?\n");

    	    fgets(newQuestion, size, stdin);

            newNode->object = newObject;
	    newNode->question = newQuestion;
            current->no_ptr = newNode;
      
            nodePrint(newNode);

  	    // Ask to play again
 	    printf("Would you like to play again?\n");
  	    fgets(response, size, stdin);

            if (!YesNoBoolean(response)){
              game = 0;
              free(newObject);
 	      free(newQuestion);
              freeTree(newNode);
            } // If
	    else 
   	      current = root; 

 	  } // Else
          game = 0;
        
        } // If 
        *response = NULL;
          
      } // If
      else {
        printf("%s", current->question);

        fgets(response, size, stdin);

        if (YesNoBoolean(response))
          current = current->yes_ptr;
        else
   	  current = current->no_ptr;
      } // Else

    } // While

  } // If
  else
    game = 0;
  //treePrint(root);
  //freeTree(root);
  //freeTree(current);
  free(response);
  free(root);
  free(node2);
  free(node3);
  free(node4);
  free(node5);
  free(node6);
  free(node7);
  free(node8);
  free(node9);
  free(current);

} // Main
