#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#define MAX 1000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, w;
pii work[MAX];
int dp[MAX][MAX];
int ans[MAX];

int dist(pii A, pii B) {
	return abs(A.first - B.first) + abs(A.second - B.second);
}

int dfs(int p1, int p2) {
	if (p1 == w || p2 == w)
		return 0;
	if (dp[p1][p2] != -1)
		return dp[p1][p2];

	int next = max(p1, p2) + 1;
	int d1, d2;

	if (p1 == 0)
		d1 = dist({ 1,1 }, work[next]);
	else
		d1 = dist(work[p1], work[next]);

	if (p2 == 0)
		d2 = dist({ n,n }, work[next]);
	else
		d2 = dist(work[p2], work[next]);


	dp[p1][p2] = min(d1 + dfs(next, p2), d2 + dfs(p1, next));
	return dp[p1][p2];
}

void tracking(int p1, int p2) {
	if (p1 == w || p2 == w)
		return;

	int next = max(p1, p2) + 1;
	int d1, d2;

	if (p1 == 0)
		d1 = dist({ 1,1 }, work[next]);
	else
		d1 = dist(work[p1], work[next]);

	if (p2 == 0)
		d2 = dist({ n,n }, work[next]);
	else
		d2 = dist(work[p2], work[next]);

	if (d1 + dp[next][p2] < d2 + dp[p1][next]) {
		cout << 1 << "\n";
		tracking(next, p2);
	}
	else {
		cout << 2 << "\n";
		tracking(p1, next);
	}
}

void solution() {
	cin >> n >> w;
	for (int i = 0; i < w; i++)
		cin >> work[i].first >> work[i].second;
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << "\n";
	tracking(0, 0);
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}