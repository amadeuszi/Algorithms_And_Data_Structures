#pragma once
#include<vector>
using namespace std;

class Graph {
	vector<int> *tab;
	int size;
	void isBoundsOk(int a, int b);
public:
	Graph(int n);
	int getSize();
	void addEdge(int a, int b);
	void addDirectedEdge(int a, int b);
	bool isDirectedEdge(int a, int b);
	bool isEdge(int a, int b);
	vector<int> neighbours(int n);
	~Graph();
};

