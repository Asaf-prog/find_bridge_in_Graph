#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(unsigned int vertices, unsigned int edges) : Graph(vertices, edges)
{
	inDegrees.resize(vertices), outDegrees.resize(vertices);
	//Make all Din & Dout to zero
	for (int& dIn : inDegrees)
		dIn = 0;

	for (int& dOut : outDegrees)
		dOut = 0;

	for (unsigned int i = 0; i < nVertices; i++)
		graph[i].pNextValidEdge = graph[i].edges.end();
}

void DirectedGraph::addEdge(unsigned int vertex1, unsigned int vertex2) {
	//This function add edges to the graph
	list<Edge>::iterator itr = find_if(graph[vertex1 - 1].edges.begin(), graph[vertex1 - 1].edges.end(), [&vertex2](const Edge& edge_) { return edge_.vertex == vertex2; });//Check if the edge is exist;

	if (itr != graph[vertex1 - 1].edges.end()) 
		throw addEdgeExeption("There is an exist edge in the graph");
	
	graph[vertex1 - 1].edges.push_back({ vertex2 });
	inDegrees[vertex2 - 1]++;
	outDegrees[vertex1 - 1]++;

	//Check if it's the first edge - to initial the pointer for the first not checked edge
	if (graph[vertex1 - 1].edges.size() == 1)
		graph[vertex1 - 1].pNextValidEdge = graph[vertex1 - 1].edges.begin();
}

bool DirectedGraph::isConnectivity() {
	//Check if the graph is Connectivity
	bool res = true;
	Visit(1);//Make visit on the first vertex
	DirectedGraph transposeG(nVertices, nEdges);
	/*Check if all the vertex on the graph used*/
	for (int i = 0; i < nVertices; i++){
		if (graph[i].colorVertex != Black) 
			res = false; //After the Visit function this vertex does not use

		graph[i].colorVertex = White;//Make vertex white again
	}
	if (!res)
		return res;
	for (int i = 0; i < nVertices; i++){
		for (const auto& edg : graph[i].edges){
			transposeG.addEdge(edg.vertex, i + 1);
		}
	}
	transposeG.Visit(1);
	/*Check if all the vertex on the transpose used*/
	for (int i = 0; i < nVertices; i++){
		if (transposeG.graph[i].colorVertex != Black) {
			res = false; //After the Visit function this vertex does not used
		}
		transposeG.graph[i].colorVertex = White;//Make vertex white again
	}
	return res;
}

void DirectedGraph::Visit(unsigned int vertex)
{
	graph[vertex - 1].colorVertex = Gray;
	for (auto& itr : graph[vertex - 1].edges){
		if (graph[itr.vertex - 1].colorVertex == White){
			Visit(itr.vertex);
		}
	}
	graph[vertex - 1].colorVertex = Black;
    endedVertex.push_back(vertex);// add to the list all the vertex that already finished
}

Graph* DirectedGraph::createDirectedGraph() {
	return nullptr;
}

void DirectedGraph::initColor() {
	for (Vertex& vertex : graph) {
		vertex.colorVertex = White;
	}
}

void DirectedGraph::shriko() {
	DirectedGraph transposeG(nVertices, nEdges);
	initColor();
    Visit(1);
	for (int i = 0; i < nVertices; i++) {
		for (const auto& edg : graph[i].edges) {
			transposeG.addEdge(edg.vertex, i + 1);
		}
	}
    // Reverse the black list
    endedVertex.reverse();
    transposeG.setEndedVertex(endedVertex);
	transposeG.VisitOnTranspose();
    transposeG.printUnSignEdge();
}
void DirectedGraph::printUnSignEdge(){
    for (int i = 0; i < nVertices; i++) {
        for (auto& itr : graph[i].edges){
            if (!itr.belongToComponent){
                cout<< "("<<itr.vertex<<","<<i+1<<")"<<endl;
            }
        }
    }
}

void DirectedGraph:: VisitOnTranspose(){
// now we're beginning from the reverses list
    for (const auto& element : endedVertex) {
        if (graph[element-1].colorVertex == White) {
            graph[element - 1].parent=element;
            VisitWithoutList(element,graph[element-1].parent);
        }
    }
}

void DirectedGraph::VisitWithoutList(unsigned int vertex,int parent)
{
    graph[vertex - 1].colorVertex = Gray;

    for (auto& itr : graph[vertex - 1].edges){

        if (graph[itr.vertex - 1].colorVertex != Black || graph[itr.vertex-1].parent == parent){
            itr.belongToComponent = true;
            graph[itr.vertex - 1].parent=parent;
            if (graph[itr.vertex - 1].colorVertex == White)
                VisitWithoutList(itr.vertex,parent);
        }
    }
    graph[vertex - 1].colorVertex = Black;
}
void DirectedGraph::setEndedVertex(list<int> endedVertex){
    this->endedVertex = endedVertex;
}
