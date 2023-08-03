#include "UndirectedGraph.h"
#include "DirectedGraph.h"


UndirectedGraph::UndirectedGraph(unsigned int vertices, unsigned int edges) : Graph(vertices, edges){
	degrees.resize(vertices);
	//Make all degrees to zero
	for (int& degree : degrees)
		degree = 0;

	for (int i = 0; i < nVertices; i++)
		graph[i].pNextValidEdge = graph[i].edges.end();
	
}

void UndirectedGraph::addEdge(unsigned int vertex1, unsigned int vertex2) {
	//This function add edges  the graph
	if (vertex1 < 1 || vertex2 < 1 || vertex1 > graph.size() || vertex2 > graph.size())
		throw validEdgeExeption("Num vertex not valid");

	list<Edge>::iterator itr = find_if(graph[vertex1 - 1].edges.begin(), graph[vertex1 - 1].edges.end(), [&vertex2](const Edge& edge_) { 
		return edge_.vertex == vertex2; });//Check if the edge exist;

	if (itr != graph[vertex1 - 1].edges.end()) {
		throw addEdgeExeption("There is an exist edge in the graph");
	}

	graph[vertex1 - 1].edges.push_back(Graph::Edge{ vertex2 });//Create the new egde and push it the last of list
	graph[vertex2 - 1].edges.push_back(Graph::Edge{ vertex1 });//Create the new same edge in the same vertex
	
	graph[vertex1 - 1].edges.back().pEdge = &(graph[vertex2 - 1].edges.back());//Initialzing the pivot for the same edge to the other same 
	graph[vertex2 - 1].edges.back().pEdge = &(graph[vertex1 - 1].edges.back());//Initialzing the pivot for the same edge to the other same 
	
	//Update degrees
	degrees[vertex2 - 1]++;
	degrees[vertex1 - 1]++;

	//Check if it's the first edge - to initial the pointer for the first not checked edge
	if (graph[vertex1 - 1].edges.size() == 1)
		graph[vertex1 - 1].pNextValidEdge = graph[vertex1 - 1].edges.begin();

	if (graph[vertex2 - 1].edges.size() == 1)
		graph[vertex2 - 1].pNextValidEdge = graph[vertex2 - 1].edges.begin();
}

bool UndirectedGraph::isConnectivity() {

	bool res = true;
	Visit(1);//Make visit on the first vertex
	/*Check if all the vertex on the graph used*/
	for (unsigned int i = 0; i < nVertices; i++){
		if (graph[i].colorVertex != Black) {
			res = false; //After the Visit function this vertex does not used
		}
		graph[i].colorVertex = White;//Make vertex white again
	}
	return res;
}
void UndirectedGraph::Visit(unsigned vertex)
{
	graph[vertex - 1].colorVertex = Gray;
	for (auto& itr : graph[vertex - 1].edges){
		if (graph[itr.vertex - 1].colorVertex == White)
			Visit(itr.vertex);	
	}
	graph[vertex - 1].colorVertex = Black;
}

void UndirectedGraph::visitAndAimTheEdges(unsigned vertex) {
	graph[vertex - 1].colorVertex = Gray;
	for (auto& itr : graph[vertex - 1].edges) {
		if (!itr.sign || graph[itr.vertex - 1].colorVertex == White) {
			this->directedGraph->addEdge(vertex, itr.vertex);
			itr.sign = true;
            itr.pEdge->sign= true;
            if (graph[itr.vertex - 1].colorVertex == White)
                visitAndAimTheEdges(itr.vertex);
		}
	}
	graph[vertex - 1].colorVertex = Black;
}

 Graph* UndirectedGraph::createDirectedGraph() {
	 
	 setDirectedGraph(new DirectedGraph(Graph::getNumberOfVertices(), Graph::getNumberOfEdges()));
	 visitAndAimTheEdges(1);
	 this->directedGraph->shriko();
     return directedGraph;
}

 void UndirectedGraph::setDirectedGraph(Graph* directedGraph) {
	 this->directedGraph = directedGraph;
 }

 void UndirectedGraph::initColor() {
	 for (Vertex& vertex : graph) {
		 vertex.colorVertex = White;
	 }
 }
 void UndirectedGraph::shriko() {

 }
 
