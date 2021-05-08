#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define pii pair<int,int>
#define MAX 10000

using namespace std;

bool visited[MAX];
int A, B;

void BFS() {
	queue<pair<int, string>>q;
	q.push(make_pair(A, ""));
	visited[A] = true;
	while (!q.empty()) {
		int curNode = q.front().first;
		string curCost = q.front().second;
		q.pop();

		if (curNode == B) {
			cout << curCost << "\n";
		}

		int N = (2 * curNode) % 10000;
		if (!visited[N]) {
			visited[N] = true;
			q.push(make_pair(N, curCost + 'D'));
		}
		
		N = (curNode - 1) < 0 ? 9999 : curNode - 1;
		if (!visited[N]) {
			visited[N] = true;
			q.push(make_pair(N, curCost + 'S'));
		}
		
		N = (curNode % 1000)*10 + curNode / 1000;
		if (!visited[N]) {
			q.push(make_pair(N, curCost + 'L'));
			visited[N] = true;
		}
		N = (curNode % 10) * 1000 + (curNode / 10);
		if (!visited[N]) {
			q.push(make_pair(N, curCost + 'R'));
			visited[N] = true;
		}
	}
}

void solution() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		memset(visited, false, sizeof(visited));
		BFS();
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}