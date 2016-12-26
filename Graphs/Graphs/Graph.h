#include<vector>
using namespace std;

class Graph {
	vector<vector<int> > graph;
	int size;
	void isBoundsOk(int a, int b);
public:
	Graph(size_t n);
	size_t getSize();
	void addEdge(int a, int b);
	void addDirectedEdge(int a, int b);
	bool isDirectedEdge(int a, int b);
	bool isEdge(int a, int b);
	vector<int> neighbours(size_t n);
	~Graph();
};

