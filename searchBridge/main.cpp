#include "Header.h"
int main() {
	int numOfVertex, numOfEdges;
	Graph* unDirectedGraph;
	Graph* DirectedGraph = nullptr;
	try {
		getGraphDetails(numOfVertex, numOfEdges);//Get n and m
		unDirectedGraph = new UndirectedGraph(numOfVertex, numOfEdges);

		addEdgesToTheGraph(unDirectedGraph, numOfEdges);// add the egeds to the graph
		if (!unDirectedGraph->isConnectivity()) 
			std::cout << "The Graph is not connected" << std::endl;
		else {
			//painted color of edge in white again
			unDirectedGraph->initColor();
			// create a directed graph with dfs
			DirectedGraph = unDirectedGraph->createDirectedGraph();
		}
	}
	catch (Exeptions& e) {

		cout << "invalid input";//Catch all the exeptions
	}
	return 0;
}