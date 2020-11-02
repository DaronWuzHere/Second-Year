#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "graph.h"
#include "graph_functions.c"

// Daronhil Mauricette
// Implementation of Dijkstra's algorithm

typedef struct node {
  int data;
  int priority;
  int struct node *next;
}Node;

int main() {
  initialize_graph()
  print

}// Main

// Implement the priority queue
int priorityQueue(Graph* mygraph, int MaxSize, Node node) {

  int length;
  int i;
  bool *visited[MaxSize];
  for (i = 0; i < MaxSize;i++)
    visited[i] = false;
  
  List* current = node.outlist;
  visited[node.data] = true;
  Node maxOutNode;  
  Node outNode;
  bool notvisited = true;

  while(current != NULL && notvisited) {
    visited[current] = true;
    maxOutNode = NULL;
    outNode = next.outlist;

    while(outNode != NULL) {
      if (!visited[outNode]) {
        if (maxOutNode == NULL)
          maxOutNode = current;
        else if (maxNodeOut < current)
          maxOutNode = current;
        if (outNode == node)
          notVisited = false;
    } // While
    current = maxOutNode;
    length = length + 1;
  } // While

  if (notVisited == false)
    return length;
  else
    return 0;
  
} // Priority Queue

void dijkstra(Graph *graph, int MaxSize, Node node) {
  
  int u;
  int z;
  int i;
  int distance[MaxSize];
  bool visited[MaxSize];
  int q = priorityQueue(graph, MaxSize, node);

  visited[node.data] = true;
  List* current = node.outlist; 
  Queue* queue = makeQueue();
  
  while(queue->front != NULL) {
    List *newNode = dequeue(queue);
    u = newNode->index;
    List * adj = graph.table[u].outlist;
    while(adj != NULL){
      if (visited[adj->index] == false) {
        enqueue(adj->index, queue);
        visited[adj->index] = true;
      } // If
      if (distance[u] +1 < distance[adj->index]) {
        distance[adj->index] = distance[u] +1; 
      } // If
     adj = adj->next;
    } // While
  }
  
  

  

} // Dijkstra's Algorithm

