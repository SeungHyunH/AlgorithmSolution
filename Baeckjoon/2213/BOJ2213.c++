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
int dp[2][MAX];
int node[MAX];
vector<int>edge[MAX];
vector<int> ans;
bool visit[MAX];

void dfs(int num) {
	visit[num] = true;
	dp[1][num] = node[num];

	for (int child : edge[num]) {
		if (!visit[child]) {
			dfs(child);

			//현재노드를 독립집합에 추가하지 않을 때 = max(자식이 독립집합에 포함된경우, 자식이 독립집합에 포함되지 않은 경우)
			dp[0][num] += max(dp[0][child], dp[1][child]);

			//현재노드가 독립집합에 추가될 때
			dp[1][num] += dp[0][child];
		}
	}
}

void tracking(int prev, int now, int flag) {
	if (flag) {
		ans.push_back(now);
		for (int child : edge[now])
		{
			//이전노드라면 패스
			if (child == prev) continue;

			//현재노드를 포함할 때 이전노드는 포함X
			tracking(now, child, 0);
		}
	}
	else {
		for (int child : edge[now])
		{
			// 이전 노드라면 패스
			if (child == prev) continue;

			if (dp[0][child] > dp[1][child])
				tracking(now, child, 0); // 다음 노드 포함 X
			else
				tracking(now, child, 1); // 다음 노드 포함 O
		}
	}
}

void solution() {
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> node[i]; }
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1);

	if (dp[0][1] > dp[1][1])
		tracking(-1, 1, 0);
	else
		tracking(-1, 1, 1);

	cout << max(dp[0][1], dp[1][1]) << "\n";
	sort(ans.begin(), ans.end());
	for (int answer : ans)
		cout << answer << " ";
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout << fixed;
	//cout.precision(2);
	solution();
	return 0;
}