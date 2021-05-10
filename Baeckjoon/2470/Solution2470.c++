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

int n;
long long arr[100001];


void solution() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	sort(arr, arr + n);
	int l = 0, r = n-1;
	long long val, al = arr[l], ar = arr[r], result = al + ar;
	while (l < r) {
		val = arr[l] + arr[r];
		if (abs(result) > abs(val)) {
			result = val;
			al = arr[l];
			ar = arr[r];
		}
		if (val <= 0) {
			l++;
		}
		else {
			r--;
		}
	}
	cout << al << " " << ar;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}