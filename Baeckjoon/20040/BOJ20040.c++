#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAX 500000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int arr[MAX];

int find(int num) {
	if (num == arr[num]) { return num; }
	return arr[num] = find(arr[num]);
}

void merge(int a, int b) {
	if (a != b) {
		arr[a] = b;
	}
}

void solution() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) { arr[i] = i; }
	for (int i = 0; i < m;i++) {
		int a, b;
		cin >> a >> b;
		int parentA = find(a);
		int parentB = find(b);
		if (parentA != parentB) {
			merge(parentA, parentB);
		}
		else {
			cout << i + 1 << "\n";
			return;
		}
	}
	cout << "0\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}