#ifndef SEARCHBRIDGE_UndirectedGraph
#define SEARCHBRIDGE_UndirectedGraph
#include "Graph.h"

class UndirectedGraph : public Graph {

	vector<int> degrees;
	 Graph* directedGraph = nullptr;
	public:

		UndirectedGraph(unsigned int vertices, unsigned int edges);
		void addEdge(unsigned int vertex1, unsigned int vertex2) noexcept(false) override;
		bool isConnectivity() override;
		void Visit(unsigned vertex) override;
		Graph* createDirectedGraph() override;
		void setDirectedGraph(Graph* directedGraph);
		void visitAndAimTheEdges(unsigned vertex);
		void initColor() override;
		void shriko()override;
};
#endif