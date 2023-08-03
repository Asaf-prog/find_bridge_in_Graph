#ifndef SEARCHBRIDGE_Graph
#define SEARCHBRIDGE_Graph
#include <list>
#include <vector>
#include <algorithm>
#include "Exeptions.h"

class Graph {
protected:
	unsigned int nVertices;
	unsigned int nEdges;
	enum  Color { White, Gray, Black };

	typedef struct edge
	{
		unsigned int vertex;//Num of the vertex
		bool visit = false;//Indication if i visit
		edge* pEdge = nullptr;//The oppisite edge
		bool belongToComponent = false;// check if this edge belong to strong bonding component
        bool sign = false;
		edge(unsigned int vertex_) : vertex(vertex_) {}

	}Edge;

	typedef struct vertex
	{
		Color colorVertex = White;//Color of the vertex for needed
		list<Edge> edges;
		list<Edge>::iterator pNextValidEdge;
        	int parent;
	}Vertex;

	vector<Vertex> graph;


public:
	Graph(unsigned int vertices, unsigned int edges) : nVertices(vertices), nEdges(edges) { graph.resize(vertices); }//when i create a new object from graph is must be directed

	virtual void addEdge(unsigned int vertex1, unsigned int vertex2)=0;
	virtual bool isConnectivity() = 0;
	virtual void Visit(unsigned int vertex) = 0;
	virtual Graph* createDirectedGraph() = 0;
	virtual void initColor() = 0;
	virtual int getNumberOfVertices() const { return nVertices; };
	virtual int getNumberOfEdges() const { return nEdges; };
    virtual void setParent(int parent,int vertex){graph[vertex -1].parent = parent;};
    virtual int getParent(int index)const{return graph[index-1].parent;};
	virtual void shriko() =0;
};
#endif
