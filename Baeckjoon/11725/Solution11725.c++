#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define pii pair<int,int>
#define MAX 100000 + 1
#define INF 987654321
using namespace std;

int N;
vector<int> tree[MAX];
int parent[MAX];
bool visited[MAX];

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < tree[cur].size(); i++) {
			int next = tree[cur][i];
			if (parent[cur] == next) { continue; }
			q.push(next);
			parent[next] = cur;
		}
	}
}

void solution() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs();

	for (int i = 2; i < N + 1; i++) {
		cout << parent[i] << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}