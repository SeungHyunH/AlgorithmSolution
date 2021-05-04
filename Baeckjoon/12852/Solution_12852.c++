#include <iostream>
using namespace std;
int dp[1000001]{ 0, };
int ans[1000001]{ 0, };
void solution() {
	int N;
	cin >> N;
	for (int i = 2; i < N + 1; i++) {
		dp[i] = dp[i - 1] + 1;
		ans[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) { dp[i] = dp[i / 2] + 1; ans[i] = i / 2; }
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) { dp[i] = dp[i / 3] + 1; ans[i] = i / 3; }
	}
	cout << dp[N]<<"\n";
	while (N != 0) {
		cout << N << ' ';
		N = ans[N];
	}
	cout << '\n';
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}