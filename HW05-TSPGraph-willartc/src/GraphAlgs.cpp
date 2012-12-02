#include "GraphAlgs.h"

	// Initializes bestTourLen and bestTour[]
	// Chooses the nodes in order of ascendin NodeID
	// Recommend trying to get a better tour choice in the future
void GraphAlgs::tspSetup(Graph* g){
	G = g;
	numTourImprovements = 0;
	bestTourLen = 0;
	bestTour.resize(G->size());
	currentTour = new int[G->size()];
	for(int i = 0; i < G->size(); i++){
		if(i + 1 >= G->size()){
			bestTour[i] = i;
			currentTour[i] = i;  // Initializes current tour
			bestTourLen += G->weight(i, 0);
		} else{
			bestTour[i] = i;
			currentTour[i] = i;  // Initializes current tour
			bestTourLen += G->weight(i, 0);
		}
	}
}

std::pair<std::vector<NodeID>, EdgeWeight> GraphAlgs::TSP(Graph* G){
	tspSetup(G);
	findBestTour(currentTour, 1, G->size());
	return std::make_pair(bestTour, bestTourLen);
}
	
	// Start cur as 1
void GraphAlgs::findBestTour(int* arr, int cur, int length){
	if( cur >= length){
		return;
	} else {
		for(int i = cur+1; i < length; i++){
			swap(arr[cur], arr[i]);
			tour(arr, length);
			findBestTour(arr, cur+1, length);
			swap(arr[cur], arr[i]);
		}
	}
}

bool GraphAlgs::tour(int* arr, int arrLen){
	double currentTourWeight = 0;
	for(int i = 1; i < arrLen; i++){
		currentTourWeight += G->weight(0, i);
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

void GraphAlgs::swap(int p, int q){
	int temp = q;
	q = p;
	p = temp;
}

