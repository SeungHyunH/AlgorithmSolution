#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAX 10000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int V, E;
vector<pair<int, pii>>arr;
int parent[MAX];

int Find(int num) {
	if (parent[num] == num) { return num; }
	return parent[num] = Find(parent[num]);
}

void solution() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		arr.push_back({ C,{A,B} });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < V; i++) { parent[i] = i; }
	int ans = 0;
	for (int i = 0; i < E; i++) {
		int parent1 = Find(arr[i].second.first), parent2 = Find(arr[i].second.second);
		if (parent1 != parent2) {
			parent[parent2] = parent1;
			ans += arr[i].first;
		}
	}
	cout << ans << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}