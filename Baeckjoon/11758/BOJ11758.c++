#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 10000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii points[3];

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
	int ans = x1 * y2 + x2 * y3 + x3 * y1;
	ans += (-y1 * x2 - y2 * x3 - y3 * x1);
	return ans;
}

void solution() {
	for (int i = 0; i < 3; i++) {
		cin >> points[i].first >> points[i].second;
	}
	int ans = ccw(points[0].first, points[1].first, points[2].first, points[0].second, points[1].second, points[2].second);
	if (ans < 0) { cout << -1; }
	else if (ans == 0) { cout << 0; }
	else { cout << 1; }
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}