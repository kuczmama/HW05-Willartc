#include "GraphAlgs.h"

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	NodeID* currentTour = tspSetup(G);

	findBestTour(1, 0,currentTour);
	std::vector<NodeID> temp;
	temp.resize(G->size());
	for(int i = 0; i < G->size(); i++){
		temp[i] = bestTour[i];
	}
	return std::make_pair(temp, bestTourWeight);
}

	// Initializes tourLen and bestTour[]
	// Chooses the nodes in order of ascendin NodeID
	// Recommend trying to get a better tour choice in the future
NodeID* tspSetup(Graph* graph){
	G = graph;
	bestTourWeight = 0;
	tourLen = G->size();
	bestTour = new NodeID[tourLen];  // An array of NodeIDs that will contain the order for the shortest tour
	NodeID* currentTour = new NodeID[tourLen];
	bestTour[0] = 0;
	currentTour[0] = 0;  // Initializes current tour
	for(int i = 0; i < tourLen-1; i++){
		bestTour[i+1] = i+1;
		currentTour[i+1] = i+1;  // Initializes current tour
		bestTourWeight += G->weight(i, i+1);
	}
	bestTourWeight += G->weight(tourLen-1, 0);
	return currentTour;
}
	
	// Start cur as 1
void findBestTour(int cur, double sum, NodeID* currentTour){
	for(int i = cur; i < tourLen-1; i++){
		swapCurrentTour(i+1, cur, currentTour);
		checkTour(currentTour);
		findBestTour(cur+1, sum, currentTour);
		swapCurrentTour(i+1, cur, currentTour);
	}
}

void checkTour(NodeID* currentTour){
	double tempWeight = 0;
	for(int i = 0; i < tourLen-1; i++){
		tempWeight += G->weight(currentTour[i+1], currentTour[i]);
	}
	tempWeight +=  G->weight(currentTour[tourLen - 1], 0);

	if(tempWeight < bestTourWeight){
		bestTourWeight = tempWeight;
		for(int q = 0; q < tourLen; q++){
			bestTour[q] = currentTour[q];
		}
	}
}

void swapCurrentTour(int p, int q, NodeID* currentTour){
	NodeID temp = currentTour[q];
	currentTour[q] = currentTour[p];
	currentTour[p] = temp;
}