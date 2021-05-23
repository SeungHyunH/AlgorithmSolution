#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 1000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<pii>Node;
vector<pair<double, pii>>Edge;
int parent[MAX];

int Find(int num) {
	if (parent[num] == num) { return num; }
	return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {
	if (a != b) { parent[b] = a; }
}

void solution() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		Node.push_back({ x,y });
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		int parent1 = Find(node1);
		int parent2 = Find(node2);
		if (parent1 != parent2) { Union(parent1, parent2); }
	}
	for (int i = 0; i < n - 1; i++) {
		int x1 = Node[i].first;
		int y1 = Node[i].second;
		for (int j = i + 1; j < n; j++) {
			int x2 = Node[j].first;
			int y2 = Node[j].second;
			int parent2 = Find(j);

			long long dx = pow(x1 - x2, 2);
			long long dy = pow(y1 - y2, 2);
			double dist = sqrt(dx + dy);
			Edge.push_back({ dist,{i + 1,j + 1} });
		}
	}

	sort(Edge.begin(), Edge.end());
	double ans = 0;
	for (int i = 0; i < Edge.size(); i++) {
		double dist = Edge[i].first;
		int node1 = Edge[i].second.first;
		int node2 = Edge[i].second.second;

		int parent1 = Find(node1);
		int parent2 = Find(node2);
		if (parent1 != parent2) {
			Union(parent1, parent2);
			ans = ans + dist;
		}
	}
	cout << ans << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(2);
	solution();
	return 0;
}