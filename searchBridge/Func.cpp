#include "Header.h"

void getGraphDetails(int& numOfVertex, int& numOfEdges) {

	std::cout << "Please enter num of Vertex:" << std::endl;
	std::cin >> numOfVertex;
	if (numOfVertex < 1)
	{
		std::cout << "Valid num of vertex, please enter again:" << endl;
		throw validInput("invalid input");
	}
	std::cout << "Please enter num of edges:" << std::endl;
	std::cin >> numOfEdges;
	if (numOfEdges < 1)
	{
		std::cout << "Valid num of edges, please enter again:" << endl;
		throw validInput("invalid input");
	}
}
void addEdgesToTheGraph(Graph* graph, int& numOfEdges)noexcept(false) {
	
	int v1, v2;
	std::cout << "Enter " << numOfEdges << " pairs of edges:" << std::endl;
	for (int i = 0; i < numOfEdges; i++)
	{
		std::cin >> v1;
		std::cin >> v2;

		graph->addEdge(v1, v2);

	}
}