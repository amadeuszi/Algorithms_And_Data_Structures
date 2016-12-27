#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int howManyLevels = 3;


int n, m;
vector<vector<vector<vector<int> > > > dynamicMax; // y - going up, x - going up, x2 - going down, level - going down

bool checkIfBoundsOk(int value, int mini, int maxi) {
	return mini <= value && value < maxi;
}

int getMax(int y, int x, int x2, int level) {
	if (level == 0 && x == x2) {
		return 0;
	}
	if (checkIfBoundsOk(y, 0, m) && checkIfBoundsOk(x2, 0, n) 
		&& checkIfBoundsOk(x, 0, n) && checkIfBoundsOk(level, 0, howManyLevels)) {
		return dynamicMax[y][x][x2][level];
	}
	else {
		return 0;
	}
}

int maxOfSet(int minY, int maxY, int minX, int maxX, int minX2, int maxX2, int minLevel, int maxLevel) {
	int maxi = 0;
	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			for (int x2 = minX2; x2 <= maxX2; x2++) {
				for (int level = minLevel; level <= maxLevel; level++) {
					if (x == x2 && level == 0) {
						continue;
					}
					maxi = max(getMax(y, x, x2, level), maxi);
				}
			}
		}
	}
	return maxi;
}

int main()
{
	cin >> m;
	cin >> n;
	
	vector<vector<int> > mapa;
	mapa.resize(m);
	for (int i = 0; i < m; i++) {
		mapa[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> mapa[i][j];
		}
	}

	dynamicMax.resize(m);
	for (int i = 0; i < m; i++) {
		dynamicMax[i].resize(n);
		for (int j = 0; j < n; j++) {
			dynamicMax[i][j].resize(n);
			for (int k = 0; k < n; k++) {
				dynamicMax[i][j][k].resize(howManyLevels);
			}
		}
	}

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			for (int x2 = 0; x2 < n; x2++) {
				if (x != x2) {
					dynamicMax[y][x][x2][0] = mapa[y][x] + mapa[y][x2] +
						maxOfSet(y - 1, y - 1, x - 2, x + 2, x2 - 1, x2 + 1, 1, 2);
				}
				
				dynamicMax[y][x][x2][1] = mapa[y][x] +
					maxOfSet(y - 1, y - 1, x - 2, x + 2, x2, x2, 0, 0);

				dynamicMax[y][x][x2][2] = mapa[y][x] +
					maxOfSet(y - 1, y - 1, x - 2, x + 2, x2, x2, 1, 1);
			}
		}
	}

	cout << maxOfSet(m - 1, m - 1, 0, n - 1, 0, n - 1, 0, 0);

	//kod
	/*
	tab[i][j][y][0] = mapa[i][j] + mapa[i][y] +
		max { tab[i - 1][j - 2:j + 2][y - 1:y + 1][1:2] };
	
	tab[i][j][y][1] = mapa[i][j] +
		max { tab[i - 1][j - 2:j + 2][y][0] | j != y };

	tab[i][j][y][2] = mapa[i][j] +
		max { tab[i - 1][j - 2:j + 2][y][1] };
		*/
    return 0;
}