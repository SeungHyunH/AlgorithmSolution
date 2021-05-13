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

int V,Max_node,Max_dist;
vector<pii> arr[MAX];
int dist[MAX];

void	 bfs(int start) {
	queue<int>q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 0; i < arr[start].size(); i++) {
			int next = arr[start][i].first;
			int next_cost = arr[start][i].second;
			if (dist[next]!=-1) { continue; }
			dist[next] = dist[start] + next_cost;
			q.push(next);
			if (Max_dist < dist[next]) {
				Max_node = next;
				Max_dist = dist[next];
			}
		}
	}
}

void solution() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int a, b, c;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) { break; }
			cin >> c;
			arr[a].push_back({ b,c });
		}
	}
	memset(dist, -1, sizeof(int) * (V + 1));
	bfs(1);

	memset(dist, -1, sizeof(int)*(V+1));
	bfs(Max_node);

	cout << Max_dist;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}