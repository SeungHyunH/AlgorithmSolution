#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 100000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, r, q;
vector<int>arr[MAX];
int tree_size[MAX];

int dfs(int cur, int prev) {
	tree_size[cur] = 1;
	for (auto next : arr[cur]) {
		if (prev == next) { continue; }
		tree_size[cur] += dfs(next, cur);
	}
	return tree_size[cur];
}

void solution() {
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	dfs(r, 0);
	for (int i = 0; i < q; i++) {
		int u; cin >> u;
		cout << tree_size[u] << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout << fixed;
	//cout.precision(2);
	solution();
	return 0;
}