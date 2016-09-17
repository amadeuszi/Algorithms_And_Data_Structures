#include "stdafx.h"
#include "FindUnion.h"


FindUnion::FindUnion(int n) {
	if (n < 1) {
		throw 42;
	}

	size = n;
	parent = new int[n + 1];
	rank = new int[n + 1];
	for (int i = 0; i <= size; i++) {
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

vector<vector<int>*>* FindUnion::result() {
	vector<vector<int>*>* t;
	t = new vector<vector<int>*>();
	t->resize(size + 1);
	for (int i = 1; i <= size; i++) {
		(*t)[i] = new vector<int>();
	}

	for (int i = 1; i <= size; i++) {
		t->at(Find(i))->push_back(i);
	}
	
	vector<vector<int>*>* finalTab;
	finalTab = new vector<vector<int>*>();
	for (int i = 1; i < t->size(); i++) {
		if ((*t)[i]->size() > 0) {
			finalTab->push_back(t->at(i));
		}
		else {
			delete (*t)[i];
		}
	}
	delete t;
	resultTab = finalTab;
	return finalTab;
}

FindUnion::~FindUnion() {
	for (int i = 0; i < resultTab->size(); i++) {
		delete resultTab->at(i);
	}
	delete resultTab;
}
