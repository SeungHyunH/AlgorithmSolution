#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define MAX 500+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int>arr[MAX];
bool visited[MAX];

bool dfs(int cur,int parent) {
	visited[cur] = true;
	for (auto child : arr[cur]) {
		if (child == parent) { continue; }
		if (visited[child]) { return false; }
		if (dfs(child, cur)==false) { return false; }
	}
	return true;
}

void solution() {
	int caseCnt = 1;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) { break; }

		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) { arr[i].clear(); }
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		int treeCnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (dfs(i, 0)) {
					treeCnt++;
				}
			}
		}
		cout << "Case " << caseCnt++;
		if (treeCnt == 0) cout << ": No trees.";
		else if (treeCnt == 1) cout << ": There is one tree.";
		else cout << ": A forest of " << treeCnt << " trees.";
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}