#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int n) {
	size = n;
	tab = new vector<int>[n + 1];
}

void Graph::addEdge(int a, int b) {
	isBoundsOk(a, b);

	tab[a].push_back(b);
	tab[b].push_back(a);
}

int Graph::getSize() {
	return size;
}

vector<int> Graph::neighbours(int n) {
	return tab[n];
}

void Graph::addDirectedEdge(int a, int b) {
	isBoundsOk(a, b);

	tab[a].push_back(b);
}

bool Graph::isDirectedEdge(int a, int b) {
	isBoundsOk(a, b);
	for (int i = 0; i < tab[a].size(); i++) {
		if (tab[a][i] == b) {
			return true;
		}
	}
}

bool Graph::isEdge(int a, int b) {
	isBoundsOk(a, b);
	return isDirectedEdge(a, b) && isDirectedEdge(b, a);
}

void Graph::isBoundsOk(int a, int b) {
	if (!(0 < a && a <= size && 0 < b && b <= size)) {
		throw 42;
	}
}

Graph::~Graph() {
}
