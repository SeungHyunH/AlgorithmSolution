#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define MAX 100000 + 1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int V,Max = 0;
vector<pii> arr[MAX];
bool visited[MAX];

int longest_child(int root) {
	int Maxs[2] = { 0,0 };
	for (auto child : arr[root]) {
		if (visited[child.first]) { continue; }
		visited[child.first] = true;
		int dist = longest_child(child.first) + child.second;
		if (dist > Maxs[0]) {
			Maxs[1] = Maxs[0];
			Maxs[0] = dist;
		}
		else if (dist > Maxs[1]) {
			Maxs[1] = dist;
		}
	}
	Max = max(Max, Maxs[0] + Maxs[1]);
	return Maxs[0];
}

void solution() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int num;
		cin >> num;
		while (1) {
			int a, b;
			cin >> a;
			if (a == -1) { break; }
			cin >> b;
			arr[num].push_back({ a,b });
		}
	}
	visited[1] = true;
	longest_child(1);
	cout << Max << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}