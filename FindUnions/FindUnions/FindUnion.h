#pragma once
using namespace std;
#include <vector>

class FindUnion {
	int size;
	int *parent;
	int *rank;
	vector<vector<int>*>* resultTab;
public:
	FindUnion(int n);
	int Find(int x);
	void Union(int x, int y);
	vector<vector<int>*>* result();
	~FindUnion();
};

