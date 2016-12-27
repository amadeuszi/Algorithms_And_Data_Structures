#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100008
int parent[MAXN];
int length[MAXN];
int howMany[MAXN];
vector<int> graph[MAXN];
vector<int> representants;
vector<int> whereRepresentants;

void addVertice(int x, int y) {
	graph[x].push_back(y);
	graph[y].push_back(x);
}

void initUnion(int n) {
	representants.resize(n); 
	whereRepresentants.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		length[i] = 0;
		howMany[i] = 1;
		representants[i - 1] = i;
		whereRepresentants[i] = i - 1;
	}
}

int Find(int x) {
	if (parent[x] == x) {
		return x;
	} 
	else {
		parent[x] = Find(parent[x]);
		return parent[x];
	}
}

void Union(int x, int y) {


	int a = Find(x);
	int b = Find(y);

	if (a == b) {
		return;
	}

	if (length[a] < length[b]) { // nie bedzie juz a
		parent[a] = b;
		howMany[b] += howMany[a];
		swap(representants[whereRepresentants[a]], representants[representants.size() - 1]);
		whereRepresentants[representants[whereRepresentants[a]]] = whereRepresentants[a];
		representants.pop_back();
	}
	else {
		parent[b] = a;
		howMany[a] += howMany[b];
		if (length[a] == length[b]) {
			length[a]++;
		}
		swap(representants[whereRepresentants[b]], representants[representants.size() - 1]);
		whereRepresentants[representants[whereRepresentants[b]]] = whereRepresentants[b];
		representants.pop_back();
	}
}

int main()
{
	int n;
	int m;
	int x;
	int y;
	cin >> n;
	cin >> m;

	initUnion(n);

	for (int i = 0; i < m; i++) {
		cin >> x;
		cin >> y;
		addVertice(x, y);
	}

	for (int i = 1; i <= n; i++) {
		vector<int>* ai = new vector<int>(representants.size());
		for (size_t j = 0; j < representants.size(); j++) {
			(*ai)[j] = 0;
		}
		
		for (size_t j = 0; j < graph[i].size(); j++) {
			int repr = Find(graph[i][j]);
			int whatIsCurrentAbstraction = Find(i);
			if (repr == whatIsCurrentAbstraction) {
				continue;
			}
			(*ai)[whereRepresentants[repr]]++;
		}
		
		vector<int>* many = new vector<int>(representants.size());
		for (size_t j = 0; j < representants.size(); j++) {
			(*many)[j] = howMany[representants[j]];
		}
		
		vector<int>* representants2 = new vector<int>(representants.size());
		for (size_t j = 0; j < representants.size(); j++) {
			(*representants2)[j] = representants[j];
		}

		for (size_t j = 0; j < representants.size(); j++) {
			if ((*ai)[j] < (*many)[j]) {
				Union(i, (*representants2)[j]);
			}
		}
	}

	cout << representants.size() << endl;
	for (int i = 1; i <= n; i++) {
		Find(i);
	}

	sort(parent + 1, parent + n + 1);

	int last = parent[1];
	int current = 1;
	int index = 0;
	for (int i = 2; i <= n; i++) {
		if (parent[i] != last) {
			representants[index] = current;
			index++;
			current = 0;
			last = parent[i];
		}
		if (i == n) {
			representants[index] = current + 1;
		}
		current++;
	}

	sort(representants.begin(), representants.end());

	for (size_t i = 0; i < representants.size(); i++) {
		cout << representants[i];
		if (i != representants.size() - 1) {
			cout << " ";
		}
	}

}

