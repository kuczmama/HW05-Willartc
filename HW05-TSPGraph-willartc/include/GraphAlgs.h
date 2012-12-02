// GraphAlgs.h
#include "Graph.h"
#include <vector>

#pragma once

	// This would be easier to write methods for if it was a class
class GraphAlgs{
private:
	double bestTourLen;
	Graph* G;
	std::vector<NodeID> bestTour;  // An array of NodeIDs that will contain the order for the shortest tour
	int numTourImprovements;  // For guaging how good firstTour is
	int* currentTour;
	

	// Not a constructor, but similar to one.  Called by TSP!
void tspSetup(Graph* g);

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

void firstTour();

void GraphAlgs::findBestTour(int* arr, int cur, int length);

	// Returns the sum of all of the weights in a tour.
	// Checks with bestTourLen after the addition of every weight
	// Updates bestTourLen and bestTour[] if a better tour is found
	// Returns false if not the best tour
bool tour(int* arr, int arrLen);

	// Helper method, swaps two ints.  Useful for exchanging NodeIDs in TSP
void swap(int p, int q);

};