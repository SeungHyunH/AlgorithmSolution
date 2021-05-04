#include <iostream>
using namespace std;
#define MAX 401
#define INF 10001

void solution() {
	int V, E,ans=INF;
	cin >> V >> E;
	int dp[MAX][MAX]{ 0, };
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			if (i != j) { dp[i][j] = INF; }
	for (int i = 0; i < E; i++) {//input
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b],c);
	}

	for (int k = 1; k <= V; k++) {//플로이드와샬알고리즘, 모든 경우를 계산하여 최소거리를 계산
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (dp[i][k] != INF && dp[k][j] != INF) {
					if (dp[i][j] > dp[i][k] + dp[k][j]) { dp[i][j] = dp[i][k] + dp[k][j]; }
				}
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) {continue;}
			ans = min(ans, dp[i][j]+dp[j][i]);
		}
	}

	if (ans == INF) { cout << -1 << "\n"; }
	else { cout << ans << "\n"; }
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}