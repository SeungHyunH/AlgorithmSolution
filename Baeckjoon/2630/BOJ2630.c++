#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 128+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, white = 0, blue = 0;
int Data[MAX][MAX];

void dfs(int x, int y, int count) {
	int paper = Data[x][y];
	for (int i = x; i < x + count; i++) {
		for (int j = y; j < y + count; j++) {
			if (paper != Data[i][j]) {
				dfs(x, y, count / 2);
				dfs(x + count / 2, y, count / 2);
				dfs(x, y + count / 2, count / 2);
				dfs(x + count / 2, y + count / 2, count / 2);
				return;
			}
		}
	}
	if (paper == 0) { white++; }
	else { blue++; }

}

void solution() {
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Data[i][j];
			if (flag && Data[i][j] != Data[0][0]) { flag = false; }
		}
	}
	if (!flag) {
		dfs(0, 0, n / 2);
		dfs(0, n / 2, n / 2);
		dfs(n / 2, 0, n / 2);
		dfs(n / 2, n / 2, n / 2);
		cout << white << "\n" << blue << "\n";
	}
	else {
		if (Data[0][0] == 0) { cout << "1\n0\n"; }
		else { cout << "0\n1\n"; }
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}