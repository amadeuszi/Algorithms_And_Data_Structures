#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > graph;
vector<int> edgesIn;
vector<int> result;
vector<int> stack;

int main()
{
    size_t n, m;
	int a, b;
	cin >> n >> m;
	graph.resize(n);
	edgesIn.resize(n);
	for (size_t i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
	}

	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < graph[i].size(); j++) {
			edgesIn[graph[i][j]]++;
		}
	}

    //We find vertices that have zero edges that go into them
    //That vertices can be first in our sort
	for (size_t i = 0; i < edgesIn.size(); i++) {
		if (edgesIn[i] == 0) {
			stack.push_back(i);
		}
	}

	while (stack.size() > 0) {
		int zeroIn = stack.at(stack.size() - 1);
		stack.pop_back();
		result.push_back(zeroIn);
		for (size_t i = 0; i < graph[zeroIn].size(); i++) {
			if (--edgesIn[graph[zeroIn][i]] == 0) {
				stack.push_back(graph[zeroIn][i]);
			}
		}
	}

    //checking whether all vertices were added
	if (result.size() == n) {
		for (size_t i = 0; i < result.size(); i++) {
			cout << ++result[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "Graph has cycles" << endl;
	}

    return 0;
}

