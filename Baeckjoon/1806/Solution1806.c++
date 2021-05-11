#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define pii pair<int,int>
#define MAX 101
#define INF 987654321
using namespace std;

long long arr[100001];

void solution() {
	int n, s;
	cin >> n>>s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int l=0, r=0,sum=0;
	int ans = INF;
	while (l <=	r) {
		if (sum >= s) {
			ans = min(ans, r - l);
			sum -= arr[l++];
		}
		else if (r == n) { break; }
		else { sum += arr[r++]; }
	}
	if (ans == INF) { cout << 0 << "\n"; }
	else { cout << ans << "\n"; }
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}