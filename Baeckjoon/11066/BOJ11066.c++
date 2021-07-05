#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#define MAX 500+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int arr[MAX];
int dp[MAX][MAX];
int psum[MAX];

void solution() {
	int t, k;
	cin >> t;
	while (t--) {
		cin >> k;
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= k; ++i) {
			cin >> arr[i];
			psum[i] = arr[i] + psum[i - 1];
		}
		for (int i = 2; i <= k; i++) {
			for (int j = i - 1; j > 0; j--) {
				dp[j][i] = INF;
				for (int l = j; l <= i; l++)
					dp[j][i] = min(dp[j][i], dp[j][l] + dp[l + 1][i]);
				dp[j][i] += psum[i] - psum[j - 1];
			}
		}
		cout << dp[1][k] << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}