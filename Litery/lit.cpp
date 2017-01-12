#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Tree {
private:
	int size;
public:
	vector<int> tab;
	Tree(size_t n) {
		size = pow(2, (ceil(log2(n)) + 1));
		tab.resize(size);
		size /= 2;
	}

	void insert(int x, int value) {
		int vertice = size + x;
		tab[vertice] = value;

		while (vertice != 1) {
			vertice /= 2;
			tab[vertice] = (tab[2 * vertice] + tab[2 * vertice + 1]);
		}
	}

	int query(int a, int b) {
		if (a > b) {
			return 0;
		}

		int verticeA = size + a;
		int verticeB = size + b;

		int result = tab[verticeA];

		if (verticeA != verticeB) {
			result += tab[verticeB];
		}

		while (verticeA / 2 != verticeB / 2) {
			if (verticeA % 2 == 0) {
				result += tab[verticeA + 1];
			}
			if (verticeB % 2 == 1) {
				result += tab[verticeB - 1];
			}
			verticeA /= 2;
			verticeB /= 2;
		}
		return result;
	}
};


int main()
{
	size_t n;
	string firstWord;
	string secondWord;
	cin >> n;
	cin >> firstWord;
	cin >> secondWord;
	Tree tree(n);
	vector<queue<int> > queues(1000);
	for (size_t i = 0; i < n; i++) {
		int letter = (int)firstWord[i];
		queues[letter].push(i);
	}

	long long result = 0;
	for (size_t i = 0; i < n; i++) {
		int letter = (int)secondWord[i];
		int index = queues[letter].front();
		queues[letter].pop();
		tree.insert(index, 1);
		result += index - tree.query(0, index - 1);
	}
	cout << result;
	return 0;
}