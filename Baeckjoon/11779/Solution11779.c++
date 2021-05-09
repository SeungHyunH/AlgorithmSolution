#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define pii pair<int,int>
#define MAX 1001
#define INF 987654321
using namespace std;

int dist[MAX];
int path[MAX];
int n,m,Start,End;
vector<pii> arr[MAX];

void solution() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}
	cin >> Start >> End;
	fill(dist, dist + n+1, INF);
	priority_queue<pii>q;
	q.push({ Start,0 });
	dist[Start] = 0;
	while (!q.empty()) {
		int cur = q.top().first, cost = -q.top().second;
		q.pop();
		if (dist[cur] < cost) { continue; }

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first, nextcost = cost + arr[cur][i].second;
			if (nextcost < dist[next]) {
				dist[next] = nextcost;
				path[next] = cur;
				q.push({ next,-nextcost });
			}
		}
	}
	cout << dist[End] << "\n";
	vector<int>ans;
	int temp = End;
	while (temp) {
		ans.push_back(temp);
		temp = path[temp];
	}
	cout << ans.size()<<"\n";
	for (int i = ans.size()-1; i >=0; i--) {
		cout << ans[i] << ' ';
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}