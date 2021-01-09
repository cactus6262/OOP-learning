#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int v)
{
	numVetices = v;
    adjs = new LinkedList[v];
}
int Graph::getVetices()
{
	return numVetices;
}
void Graph::addEdge(int src, int dest)
{
	if (src < numVetices && dest < numVetices)
	{
		adjs[src].insertNodeBeforeHead(dest);
		adjs[dest].insertNodeBeforeHead(src);
	}
}

void Graph::printGraph()
{
	std::cout << "Adjacency List of Undirected Graph" << endl;
	Node* temp;
	for (int i = 0; i < numVetices; i++) {
		std::cout << "|" << i << "| => ";
		temp = (adjs[i]).getHead();

		while (temp != NULL) {
			cout << "[" << temp->data << "] -> ";
			temp = temp->nextNode;
		}
		std::cout << "NULL" << endl;
	}
}