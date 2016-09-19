// TopologicalSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> graph;
vector<int> edgesIn;
vector<int> result;
vector<int> stack;

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	graph.resize(n);
	edgesIn.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			edgesIn[graph[i][j]]++;
		}
	}
	
	for (int i = 0; i < edgesIn.size(); i++) {
		if (edgesIn[i] == 0) {
			stack.push_back(i);
		}
	}

	while (stack.size() > 0) {
		int zeroIn = stack.at(stack.size() - 1);
		stack.pop_back();
		result.push_back(zeroIn);
		for (int i = 0; i < graph[zeroIn].size(); i++) {
			if (--edgesIn[graph[zeroIn][i]] == 0) {
				stack.push_back(graph[zeroIn][i]);
			}
		}
	}

	bool isOk = true;
	for (int i = 0; i < edgesIn.size(); i++) {
		if (edgesIn[i] > 0) {
			isOk = false;
			break;
		}
	}
	
	if (isOk) {
		for (int i = 0; i < result.size(); i++) {
			cout << ++result[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "Graf isn't acyclical" << endl;
	}

    return 0;
}

