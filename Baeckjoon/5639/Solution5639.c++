#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define MAX 10000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int arr[MAX];

void search(int left,int right) {
	if (left >= right) { return; }
	int root = arr[left];
	int mid = lower_bound(arr + left + 1, arr + right, root) - arr;
	search(left + 1, mid);
	search(mid, right);
	cout << root << "\n";
}

void solution() {
	int i = 0;
	for (i = 0; cin >> arr[i]; i++) { continue; }
	search(0, i);
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}