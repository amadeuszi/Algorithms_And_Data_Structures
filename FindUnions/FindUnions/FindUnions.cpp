#include "FindUnion.h"
#include <iostream>

using namespace std;

int main() {
	FindUnion set(10);
	set.Union(1, 3);
	set.Union(3, 7);
	set.Union(7, 2);
	set.Union(8, 9);
	//true:
	cout << "true: " << endl;
	cout << (set.Find(3) == set.Find(1)) << endl;
	cout << (set.Find(1) == set.Find(7)) << endl;
	cout << (set.Find(1) == set.Find(2)) << endl;
	//false:
	cout << "false: " << endl;
	cout << (set.Find(1) == set.Find(4)) << endl;
	cout << (set.Find(1) == set.Find(5)) << endl;
	cout << (set.Find(4) == set.Find(5)) << endl;
	vector<vector<int> > result = set.result();
	cout << "tyle jest klas abstrakcji: " << result.size() << endl;
	for (size_t i = 0; i < result.size(); i++) {
		for (size_t j = 0; j < result.at(i).size(); j++) {
			cout << result.at(i).at(j) << " ";
		}
		cout << endl;
	}
    return 0;
}

