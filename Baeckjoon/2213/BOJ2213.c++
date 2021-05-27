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

			//�����带 �������տ� �߰����� ���� �� = max(�ڽ��� �������տ� ���ԵȰ��, �ڽ��� �������տ� ���Ե��� ���� ���)
			dp[0][num] += max(dp[0][child], dp[1][child]);

			//�����尡 �������տ� �߰��� ��
			dp[1][num] += dp[0][child];
		}
	}
}

void tracking(int prev, int now, int flag) {
	if (flag) {
		ans.push_back(now);
		for (int child : edge[now])
		{
			//��������� �н�
			if (child == prev) continue;

			//�����带 ������ �� �������� ����X
			tracking(now, child, 0);
		}
	}
	else {
		for (int child : edge[now])
		{
			// ���� ����� �н�
			if (child == prev) continue;

			if (dp[0][child] > dp[1][child])
				tracking(now, child, 0); // ���� ��� ���� X
			else
				tracking(now, child, 1); // ���� ��� ���� O
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