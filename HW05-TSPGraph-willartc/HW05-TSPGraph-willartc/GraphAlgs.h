// GraphAlgs.h

#include "Graph.h"
#include <vector>

#pragma once

static Graph* G;				// The graph
static double bestTourWeight;	// This is the min we check against
static int tourLen;				// The number of nodes
static NodeID* bestTour;		// An array of NodeIDs that will contain the order for the shortest tour

	// Not a constructor, but similar to one.  Called by TSP
NodeID* tspSetup(Graph* graph);

	// Arranges currentTour into all of the necessary permutations
	// Calls checkTour for each permutation
void findBestTour(int cur, double sum, NodeID* currentTour);

	// Sums all of the weights in a tour.
	// Checks with bestTourLen after the addition of every weight
	// Updates bestTourLen and bestTour[] if a better tour is found
void checkTour(NodeID* currentTour);

	// Used for exchanging NodeIDs in findBestTour()
void swapCurrentTour(int p, int q, NodeID* currentTour);


/*
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 * vists every node exactly once (with exception of the first node, which is repeated as the 
 * last node in the cycle.)
 * 
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
 *  being the length of that path (do NOT forget to include the edge from the last node back to
 *  the start node in the total length.
 *
 * Preconditions: 
 *     G is undirected.
 *     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
 */

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G);