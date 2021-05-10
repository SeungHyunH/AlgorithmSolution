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

int n,x;
int Data[100000];


void solution() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> Data[i]; }
	cin >> x;
	sort(Data, Data+n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (x == Data[i] + Data[lower_bound(Data, Data + n, x - Data[i]) - Data]) { ans++; }
	}
	cout << ans / 2 << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}