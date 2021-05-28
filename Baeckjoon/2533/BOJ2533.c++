#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 1000000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int>arr[MAX];
int dp[MAX][2];
bool visit[MAX];
int n;

void dfs(int cur) {
	visit[cur] = true;
	for (int child : arr[cur]) {
		if (!visit[child]) {
			dfs(child);
			dp[cur][1] += min(dp[child][0], dp[child][1]);
			dp[cur][0] += dp[child][1];
		}
	}
}

void solution() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
		dp[i][1] = 1;
	}
	dp[n][1] = 1;
	dfs(1);
	cout << min(dp[1][0], dp[1][1]) << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout << fixed;
	//cout.precision(2);
	solution();
	return 0;
}