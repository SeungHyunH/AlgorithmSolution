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

int n;
int dp[MAX][2];
int w[MAX];
bool visit[MAX];
vector<int>arr[MAX];

void dfs(int num) {
	visit[num] = true;
	dp[num][1] = w[num];
	for (int child : arr[num]) {
		if (!visit[child]) {
			dfs(child);
			dp[num][0] += max(dp[child][1], dp[child][0]);
			dp[num][1] += dp[child][0];
		}
	}
}

void solution() {
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> w[i]; }
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout << fixed;
	//cout.precision(2);
	solution();
	return 0;
}