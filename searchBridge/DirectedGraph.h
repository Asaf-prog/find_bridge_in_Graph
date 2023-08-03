#include "Graph.h"
#ifndef SEARCHBRIDGE_DirectedGraph
#define SEARCHBRIDGE_DirectedGraph
class DirectedGraph : public Graph {

	private:
		vector<int> inDegrees;
		vector<int> outDegrees;
        list<int> endedVertex;

	public:
		DirectedGraph(unsigned int vertices, unsigned int edges);
		void addEdge(unsigned int vertex1, unsigned int vertex2) noexcept(false) override;
		bool isConnectivity() override;
		void Visit(unsigned int vertex) override;
		Graph* createDirectedGraph() override;
		 void initColor() override;
		 void shriko()override;
         void VisitOnTranspose();
         void VisitWithoutList(unsigned int vertex,int parent);
         void printUnSignEdge();
         void setEndedVertex(list<int> endedVertex);
};
#endif