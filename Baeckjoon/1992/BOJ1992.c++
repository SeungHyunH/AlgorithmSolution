#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 64+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int arr[MAX][MAX];

void comp(int x, int y, int size) {
	bool flag = false;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[x][y] != arr[i][j])
				flag = true;
		}
	}

	if (flag) {
		cout << "(";
		comp(x, y, size / 2);
		comp(x, y + size / 2, size / 2);
		comp(x + size / 2, y, size / 2);
		comp(x + size / 2, y + size / 2, size / 2);
		cout << ")";
	}
	else {
		cout << arr[x][y];
	}
}

void solution() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j] - '0';
	}
	comp(0, 0, n);
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}