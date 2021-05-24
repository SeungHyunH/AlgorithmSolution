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

struct Point {
	int idx;
	int x;
	int y;
	int z;
};

struct Edge {
	int src;
	int dst;
	int cost;
};

int n;
vector<Point> planets;
vector<Edge> edges;
vector<int> parent;

int Find(int num) {
	if (parent[num] == num) { return num; }
	return parent[num] = Find(parent[num]);
}

void solution() {
	cin >> n;
	planets = vector<Point>(n);
	edges = vector<Edge>(3 * (n - 1));
	parent.resize(n);

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		planets[i] = { i,x,y,z };
		parent[i] = i;
	}
	sort(planets.begin(), planets.end(), [](Point& a, Point& b) {return a.x < b.x; });
	for (int i = 0; i < n - 1; i++)
		edges[i] = { planets[i].idx, planets[i + 1].idx, planets[i + 1].x - planets[i].x };
	sort(planets.begin(), planets.end(), [](Point& a, Point& b) {return a.y < b.y; });
	for (int i = 0; i < n - 1; i++)
		edges[n - 1 + i] = { planets[i].idx, planets[i + 1].idx, planets[i + 1].y - planets[i].y };
	sort(planets.begin(), planets.end(), [](Point& a, Point& b) {return a.z < b.z; });
	for (int i = 0; i < n - 1; i++)
		edges[2 * (n - 1) + i] = { planets[i].idx, planets[i + 1].idx, planets[i + 1].z - planets[i].z };

	sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {return a.cost < b.cost; });

	ll ans = 0;
	for (auto& edge : edges) {
		int parent1 = Find(edge.src);
		int parent2 = Find(edge.dst);
		if (parent1 != parent2) {
			parent[parent2] = parent1;
			ans += edge.cost;
		}
	}
	cout << ans << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout << fixed;
	//cout.precision(2);
	solution();
	return 0;
}