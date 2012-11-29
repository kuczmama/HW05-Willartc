#include "listGraph.h"

ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
	for(int i = 0; i < edgeList.size(); i++){
		//edgeList[i] = 
	}
}

  // Modifiers
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair tPair = (*it);  // The star is NOT the dereference operator, the * has been overloaded
		if(tPair.first == v){
			tPair.second = weight;
		}
	}
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
}
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const{
	return edgeList[u].size();
}


//unsigned ListGraph::size() const;
unsigned ListGraph::numEdges() const{
	int numEdges = 0;
	for(int i = 0; i < edgeList.size(); i++){
		numEdges += edgeList[i].size();
	}
	return numEdges;
}
  