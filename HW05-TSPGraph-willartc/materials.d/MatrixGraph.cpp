#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){
	M.resize(num_nodes);
	for(int i = 0; i < M.size(); i++){
		M[i].resize(num_nodes);
	}
}

MatrixGraph::~MatrixGraph(){
}

  // Modifiers
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	M[u][v] = weight;
}
  
  // Inspectors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	// Stupid question: why don't we store NWPairs in the matrix from the beginning?
	// It shouldn't affect the runtime of the other functions . . .
	return M[u];
}

unsigned MatrixGraph::degree(NodeID u) const{
}

unsigned MatrixGraph::size() const{
}

unsigned MatrixGraph::numEdges() const{
}

std::vector<std::vector<EdgeWeight> > M;
int num_edges;