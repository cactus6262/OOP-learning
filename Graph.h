#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "LinkedList.h"

class Graph
{
public:
	Graph(int v);
	int getVetices();
	void addEdge(int src, int dest);
	void printGraph();
private:
	int numVetices;
	LinkedList* adjs;
};

#endif
