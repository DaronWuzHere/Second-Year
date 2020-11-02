#include "graph.h"

int main(int argc,char *argv[])
{
  Graph mygraph;

  read_graph(&mygraph,argv[1]);

  int outdegree;
  int minIndegree;
  int maxIndegree;

  printf("Readings from graph %s\n", argv[1])
  
  for(i = 0; mygraph->outdegree > i; i++)
  {
    outdegree = i;
  }
  
  printf("Max out-degree is %d at node %d\n", outdegree, node);
  return(0);
}
