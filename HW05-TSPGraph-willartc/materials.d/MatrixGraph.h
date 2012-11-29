// MatrixGraph.h

#include <vector>
#include "Graph.h"

#pragma once

typedef std::list<NWPair> EList;

class MatrixGraph : public Graph {
 public:
  MatrixGraph(unsigned num_nodes);
  ~MatrixGraph();

  // Modifiers
  void addEdge(NodeID u, NodeID v, EdgeWeight weight);
  
  // Inspectors
  EdgeWeight weight(NodeID u, NodeID v) const;
  std::list<NWPair> getAdj(NodeID u) const;
  unsigned degree(NodeID u) const;
  unsigned size() const;
  unsigned numEdges() const;

 private:
  MatrixGraph() {;} // The ; has implemented this constructor

  std::vector<std::vector<EdgeWeight> > M;
  int num_edges;
};
