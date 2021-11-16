#include <iostream>
#include <queue>
#include <vector>
#define MAX 32000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int edge[MAX];
vector<vector<int>>graph(MAX, vector<int>());
void solution() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		edge[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (edge[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++) {
			edge[graph[cur][i]]--;
			if (!edge[graph[cur][i]])
				q.push(graph[cur][i]);
		}
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}