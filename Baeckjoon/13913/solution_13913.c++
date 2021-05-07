#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define pii pair<int,int>
#define MAX 100001

using namespace std;

int parent[MAX];
bool visited[MAX];
vector<int> path;

int BFS() {
	int N, K;
	cin >> N >> K;
	queue<pii>q;
	q.push(pii(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		int curNode = q.front().first;
		int curCost = q.front().second;
		q.pop();

		if(curNode == K) {
			int index = curNode;
			while (index != N) {
				path.push_back(index);
				index = parent[index];
			}
			path.push_back(N);
			return curCost;
		}
		if (curNode + 1 < MAX && !visited[curNode + 1]){
			q.push(make_pair(curNode + 1, curCost + 1));
			visited[curNode + 1] = true;
			parent[curNode + 1] = curNode;
		}

		if (curNode - 1 >= 0 && !visited[curNode - 1])
		{
			q.push(make_pair(curNode - 1, curCost + 1));
			visited[curNode - 1] = true;
			parent[curNode - 1] = curNode;
		}

		if (curNode * 2 < MAX && !visited[curNode * 2])
		{
			q.push(make_pair(curNode * 2, curCost + 1));
			visited[curNode * 2] = true;
			parent[curNode * 2] = curNode;
		}
	}
}

void solution() {
	cout << BFS() << "\n";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}