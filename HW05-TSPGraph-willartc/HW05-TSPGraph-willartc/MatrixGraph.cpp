#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	M.resize(num_nodes);
	for(int i = 0; i < M.size(); i++){
		M[i].resize(num_nodes);
		for(int z = 0; z < num_nodes; z++){
			M[i][z] = 0;
		}
	}
}

MatrixGraph::~MatrixGraph(){
}

  // Modifiers
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	M[u][v] = weight;
	M[v][u] = weight;
	num_edges++;
}
  
  // Inspectors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	// Stupid question: why don't we store NWPairs in the matrix from the beginning?
	// It shouldn't affect the runtime of the other functions . . .
	
	std::list<NWPair>* rList = new std::list<NWPair>();
	for(int i = 0; i < M[u].size(); i++){
		if(M[u][i] != 0){
			rList->push_back(std::make_pair(i, M[u][i]));
		}
	}
	
	return *rList;
}

unsigned MatrixGraph::degree(NodeID u) const{
	return getAdj(u).size();
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}