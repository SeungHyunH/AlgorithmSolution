#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define MAX 10000 + 1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int N, Max_Dist = 0;
vector<pii> arr[MAX];
int dist[MAX];

int bfs(int start) {
	memset(dist, -1, sizeof(int) * (N + 1));
	int Max_Node = start;
	queue<int>q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 0; i < arr[start].size(); i++) {
			int next = arr[start][i].first;
			int next_cost = arr[start][i].second;
			if (dist[next] != -1) { continue; }
			dist[next] = dist[start] + next_cost;
			q.push(next);
			if (Max_Dist < dist[next]) {
				Max_Node = next;
				Max_Dist = dist[next];
			}
		}
	}
	return Max_Node;
}

void solution() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	
	bfs(bfs(1));

	cout << Max_Dist <<"\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}