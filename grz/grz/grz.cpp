// grz.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "stdafx.h"

using namespace std;

vector<vector<int> > graph;
vector<vector<bool> > mountain;
vector<vector<bool> > valley;

vector<int> parent;

int Find(int x) {
	if (parent[x] < 0) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}

}

void Union(int x, int y) {
	int a = Find(x);
	int b = Find(y);
	if (a != b) {
		if (parent[a] > parent[b]) { // 'a' becomes a node
			swap(a, b);
		}
		parent[a] += parent[b];
		parent[b] = a;
	}
}

int n;
int index(int i, int j) {
	return i * n + j;
}


bool isBounds(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

int decryptX(int v) {
	return v / n;
}

int decryptY(int v) {
	return v % n;
}


int main()
{
	cin >> n;
	graph.resize(n);
	int unions = n * n;
	parent.resize(unions);
	mountain.resize(n);
	valley.resize(n);
	for (int i = 0; i < n; i++) {
		graph[i].resize(n);
		mountain[i].resize(n);
		valley[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			mountain[i][j] = true;
			valley[i][j] = true;
		}
	}

	for (int i = 0; i < unions; i++) {
		parent[i] = -1;
	}

	int XXX[] = {1, 1, 1, 0, 0, -1, -1, -1};
	int YYY[] = { -1, 0, 1, 1, -1, -1, 0, 1 };

	int x, y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 8; k++) {
				x = i + XXX[k];
				y = j + YYY[k];
				if (isBounds(x, y)) {
					if (graph[i][j] == graph[x][y]) {
						Union(index(i, j), index(x, y));
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 8; k++) {
				x = i + XXX[k];
				y = j + YYY[k];
				if (isBounds(x, y)) {
					if (graph[i][j] < graph[x][y]) {
						mountain[decryptX(Find(index(i, j)))][decryptY(Find(index(i, j)))] = false;
					}
					if (graph[i][j] > graph[x][y]) {
						valley[decryptX(Find(index(i, j)))][decryptY(Find(index(i, j)))] = false;
					}
				}
			}
		}
	}

	int howMountain = 0;
	int howValley = 0;

	for (int i = 0; i < unions; i++) {
		if (parent[i] < 0) {
			howMountain += (int)mountain[decryptX(i)][decryptY(i)];
			howValley += (int)valley[decryptX(i)][decryptY(i)];
		}
	}

	cout << howMountain << " " << howValley << endl;

    return 0;
}

