#include "GraphAlgs.h"

	// Initializes bestTourLen and bestTour[]
	// Chooses the nodes in order of ascendin NodeID
	// Recommend trying to get a better tour choice in the future
void tspSetup(Graph* graph){
	G = graph;
	numTourImprovements = 0;
	bestTourLen = 0;
	bestTour.resize(G->size());
	currentTour.resize(G->size());
	bestTour[0] = 0;
	currentTour[0] = 0;
	for(int i = 1; i < G->size(); i++){
		bestTour[i] = i;
		currentTour[i] = i;  // Initializes current tour
		bestTourLen += G->weight(i, i-1);
	}
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	tspSetup(G);
	findBestTour(currentTour, 1, G->size());
	return std::make_pair(bestTour, bestTourLen);
}
	 
void findBestTour(std::vector<NodeID> arr, int cur, int length){
	if( cur >= length-1){
		return;
	} else {
		for(int i = cur+1; i < length; i++){
			swap(arr, arr[cur], arr[i]);
			tour(arr, length);
			findBestTour(arr, cur+1, length);
			swap(arr, arr[cur], arr[i]);
		}
	}
}

bool tour(std::vector<NodeID> arr, int arrLen){
	double currentTourWeight = 0;
	for(int i = 1; i < arrLen; i++){
		currentTourWeight += G->weight(arr[0], arr[i]);
		if(currentTourWeight >= bestTourLen){
			return false;
		}
	}
	bestTourLen = currentTourWeight;
	for(int i = 0; i < arrLen; i++){
		bestTour[i] = currentTour[i];
	}
	numTourImprovements++;
	return true;
}

void swap(std::vector<NodeID> arr, int p, int q){
	int temp = arr[q];
	arr[q] = arr[p];
	arr[p] = temp;
}