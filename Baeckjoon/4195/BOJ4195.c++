#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAX 200000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int t, f;
map<string, int> name;
int arr[MAX];
int dist[MAX];

int find(int num) {
	if (num == arr[num]) { return num; }
	return arr[num]=find(arr[num]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) { 
		if (dist[a] < dist[b]) {swap(a, b);}
		arr[b] = a;
		dist[a] += dist[b];
		dist[b] = 0;
	}
	cout << dist[a]<<"\n";
}

void solution() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> f;
		int cnt = 0;
		for (int j = 0; j < 2 * f; j++) { dist[j] = 1; arr[j] = j; }
		for (int j = 0; j < f; j++) {
			string a,b;
			cin >> a>>b;
			if (name.find(a) == name.end()) {name[a] = cnt++;}
			if (name.find(b) == name.end()) {name[b] = cnt++;}
			merge(name[a], name[b]);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}