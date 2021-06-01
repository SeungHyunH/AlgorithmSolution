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

vector<pair<double, double>>points;
int n;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double ans = x1 * y2 + x2 * y3 + x3 * y1;
	ans += (-y1 * x2 - y2 * x3 - y3 * x1);
	return ans / 2.0;
}

void solution() {
	cin >> n;
	points = vector<pair<double, double>>(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	double ans = 0;
	for (int i = 1; i < n; i++)
		ans += ccw(points[0].first, points[i - 1].first, points[i].first, points[0].second, points[i - 1].second, points[i].second);
	cout << abs(ans);
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(1);
	cout << fixed;
	solution();
	return 0;
}