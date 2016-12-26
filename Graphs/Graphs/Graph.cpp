#include "Graph.h"


Graph::Graph(size_t n) {
	size = n;
	graph.resize(n);
}

void Graph::addEdge(int a, int b) {
	isBoundsOk(a, b);

	graph[a].push_back(b);
	graph[b].push_back(a);
}

size_t Graph::getSize() {
	return size;
}

vector<int> Graph::neighbours(size_t n) {
    isBoundsOk(n, n);
	return graph[n];
}

void Graph::addDirectedEdge(int a, int b) {
	isBoundsOk(a, b);

	graph[a].push_back(b);
}

bool Graph::isDirectedEdge(int a, int b) {
	isBoundsOk(a, b);
	for (size_t i = 0; i < graph[a].size(); i++) {
		if (graph[a][i] == b) {
			return true;
		}
	}
    return false;
}

bool Graph::isEdge(int a, int b) {
	isBoundsOk(a, b);
	return isDirectedEdge(a, b) && isDirectedEdge(b, a);
}

void Graph::isBoundsOk(int a, int b) {
	if (!(0 <= a && a < size && 0 <= b && b < size)) {
		throw 42;
	}
}

Graph::~Graph() {
}
