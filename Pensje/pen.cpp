
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;


class Wages {
	vector<vector<int> > tree;
	vector<int> wage;
	vector<int> sizeOfTrees;
	stack<int> K;
	stack<int> P;
	vector<bool> ambiguous;
	vector<int> parentWage;
	stack<int> treesT;

	/**
	* Counts the sizes of every subtree.
	*/
	void countSizes(int vertix) {
		int sum = 1;
		for (size_t i = 0; i < tree[vertix].size(); i++) {
			int numOfVertix = tree[vertix][i];
			countSizes(numOfVertix);
			sum += sizeOfTrees[numOfVertix];
			parentWage[numOfVertix] = wage[vertix];
		}
		sizeOfTrees[vertix] = sum;
	}

	/**
	* It finds the maximum trees that are all with zeroWages. 
	* It means that all og the vertices have non public wage.
	* It copies these roots to the treesT stack.
	*/
	void findSubTrees(int vertix) {
		bool isSonsWageZero = true;
		for (size_t i = 0; i < tree[vertix].size(); i++) {
			int numOfVertix = tree[vertix][i];
			if (wage[numOfVertix] != 0) {
				isSonsWageZero = false;
				break;
			}
		}
		if (isSonsWageZero && wage[vertix] == 0) {
			treesT.push(vertix);
		}
		else {
			for (size_t i = 0; i < tree[vertix].size(); i++) {
				findSubTrees(tree[vertix][i]);
			}
		}
	}

	/**
	* It sorts every vertix in treesT according to parentWage[vertix]
	*/
	void sortTreesT() {
		vector<pair<int, int> > sorting;
		while (!treesT.empty()) {
			int vertixOfTree = treesT.top();
			treesT.pop();
			sorting.push_back(pair<int, int>(parentWage[vertixOfTree], vertixOfTree));
		}
		sort(sorting.begin(), sorting.end());
		for (size_t i = sorting.size(); i > 0; i--) {
			treesT.push(sorting[i - 1].second);
		}
	}

	/**
	* It adds wages to the vertices until the first "fork".
	*/
	void addWagesToVertices(int vertix, stack<int>& wages) {
		wage[vertix] = wages.top();
		wages.pop();
		if (tree[vertix].size() == 1) {
			addWagesToVertices(tree[vertix][0], wages);
		}
	}

	/**
	* It shows the rsults.
	*/
	void showResults() {
		for (size_t i = 0; i < wage.size(); i++) {
			if (ambiguous[wage[i]]) {
				cout << "0" << endl;
			}
			else {
				cout << wage[i] << endl;
			}
		}
	}

	/**
	* The main Algorithm
	*/
	void mainAlgorithm() {
		while (!treesT.empty()) {
			int myRoot = treesT.top();
			treesT.pop();
			stack<int> treeWages;
			for (int i = 0; i < sizeOfTrees[myRoot]; i++) {
				treeWages.push(K.top());
				K.pop();
			}
			if (K.empty() || K.top() > parentWage[myRoot]) {
				addWagesToVertices(myRoot, treeWages);
				while (!P.empty() && P.top() < parentWage[myRoot]) {
					P.pop();
				}
			}
			else {
				while (!P.empty() && P.top() < parentWage[myRoot]) {
					ambiguous[P.top()] = true;
					P.pop();
				}
			}
		}
	}

	/**
	* It prepares input.
	* @returns Returns main root of the whole tree.
	*/
	int prepareInput() {
		size_t n;
		int p, z;

		cin >> n;
		
		tree.resize(n);
		wage.resize(n);
		sizeOfTrees.resize(n);
		ambiguous.resize(n + 1);
		parentWage.resize(n);
		
		vector<bool> isPublicWages(n + 1);
		int mainRoot = 0;
		for (size_t i = 0; i < n; i++) {
			cin >> p;
			cin >> z;
			p--;
			wage[i] = z;
			isPublicWages[z] = true;

			if (p == i) {
				mainRoot = p;
				parentWage[mainRoot] = z + 1;
			}
			else {
				tree[p].push_back(i);
			}
		}

		for (size_t i = n; i > 0; i--) {
			if (!isPublicWages[i]) {
				K.push(i);
				P.push(i);
			}
		}
		return mainRoot;
	}

public:
	Wages() {
		ios_base::sync_with_stdio(0);
		int mainRoot = prepareInput();
		countSizes(mainRoot);
		findSubTrees(mainRoot);
		sortTreesT();

		mainAlgorithm();

		showResults();
	}
	
};

int main()
{
	Wages *w = new Wages();
	delete w;
    return 0;
}

