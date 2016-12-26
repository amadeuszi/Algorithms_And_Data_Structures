#ifndef FIND_UNION_H
#define FIND_UNION_H

#include <vector>

class FindUnion {
	int size;
	std::vector<int> parent;
	std::vector<int> rank;
public:
	FindUnion(int n);
	int Find(int x);
	void Union(int x, int y);
    std::vector<std::vector<int> > result();
	~FindUnion();
};

// your code
#endif