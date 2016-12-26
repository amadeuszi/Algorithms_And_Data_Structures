#include "FindUnion.h"
using namespace std;

FindUnion::FindUnion(int n) {
	if (n < 1) {
		throw 42;
	}

	size = n;
	parent.resize(n + 1);
	rank.resize(n + 1);
	for (size_t i = 0; i < parent.size(); i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int FindUnion::Find(int x) {
	if (!(0 < x && x <= size)) {
		throw 42;
	}

	if (parent[x] == x) {
		return x;
	}
	else {
		parent[x] = Find(parent[x]);
        return parent[x];
	}
}

void FindUnion::Union(int x, int y) {
	int a = Find(x);
	int b = Find(y);
	
	if (a == b) { // it is already in the same Class of abstraction
		return;
	}

	if (rank[a] < rank[b]) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
		if (rank[a] == rank[b]) { //tree grows in depth +1
			rank[a]++;
		}
	}
}

vector<vector<int> > FindUnion::result() {
	vector<vector<int> > classesOfAbstraction;
	classesOfAbstraction.resize(size + 1);

	for (int i = 1; i <= size; i++) {
		classesOfAbstraction[Find(i)].push_back(i);
	}
	
	vector<vector<int> > finalTab;
	for (size_t i = 1; i < classesOfAbstraction.size(); i++) {
		if (classesOfAbstraction[i].size() > 0) {
			finalTab.push_back(classesOfAbstraction[i]);
		}
	}

	return finalTab;
}

FindUnion::~FindUnion() {
}
