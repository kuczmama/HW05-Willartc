#include "listGraph.h"

ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
	num_edges = 0;
}
ListGraph::~ListGraph(){
}

  // Modifiers
// addEdge updates if the node exists, adds otherwise
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair tPair = (*it);  // The star is NOT the dereference operator, the * has been overloaded
			if(tPair.first == v){  // If there is an edge between u and v, we'll find it with this if
			tPair.second = weight;
			//  Since we found the first name of the edge, we know it was inserted
			//  Therefore, we know that the opposite name should also exist
			//  Once we have updated both names with the new weight, we're done
			//  So we can return without having to finish either for loop
			//  So this isn't really a nested for loop, each loop should only run once
			for(it = edgeList[v].begin(); it != edgeList[v].end(); it++){
				tPair = (*it);
				if(tPair.first == u){
					tPair.second = weight;
					return;
				}
			}
		}
	}
	// If the first for loop doesn't find the edge, insert both of its names
	edgeList[u].push_back(std::make_pair(v, weight));

	edgeList[v].push_back(std::make_pair(u, weight));
	num_edges++;  //  One edge, two names: (u,v) and (v,u)
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