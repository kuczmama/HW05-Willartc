#include "listGraph.h"

ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
}
ListGraph::~ListGraph(){
}

  // Modifiers
// addEdge updates if the node exists, adds otherwise
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	EList::const_iterator it;
	bool insertDuplicate = false;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair tPair = (*it);  // The star is NOT the dereference operator, the * has been overloaded
		if(tPair.first == v){
			tPair.second = weight;
		}
	}
	// Insert complimentary edge name because the graph is undirected
	if(insertDuplicate){
		for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
			NWPair tPair = (*it);  // The star is NOT the dereference operator, the * has been overloaded
			if(tPair.first == v){
				tPair.second = weight;
				num_edges++;
				return;
			}
		}
	}
	NWPair tPair;  // Local variable scope errors?
	tPair.first = v;
	tPair.second = weight;
	edgeList[u].push_back(tPair);
	tPair.first = u;	// Insert complimentary edge name
	edgeList[v].push_back(tPair);
	num_edges++;
}

  // Inspectors: Can read, not write
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair tPair = (*it);  // The star is NOT the dereference operator, the * has been overloaded
		if(tPair.first == v){
			return tPair.second;
		}
	}
	return NULL;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const{
	return edgeList[u].size();
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

//unsigned ListGraph::size() const;
unsigned ListGraph::numEdges() const{
	return num_edges;
}