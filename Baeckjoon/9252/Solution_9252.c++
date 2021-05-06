#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int dp[1001][1001];
void solution() {
	string A, B,ans="";
	cin >> A >> B;
	A = '0' + A;
	B = '0' + B;
	int lenA = A.size(), lenB = B.size();
	for (int i = 0; i < lenA; i++) {
		for (int j = 0; j < lenB; j++) {
			if (i == 0 || j == 0) { dp[i][j] = 0; continue; }
			if (A[i] == B[j]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
			else { dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); }
		}
	}
	int i = lenA-1, j = lenB-1;
	while (dp[i][j] != 0) {
		if (dp[i][j] == dp[i][j - 1]) { 
			j--; 
		}
		else if (dp[i][j] == dp[i - 1][j]) { 
			i--; 
		}
		else if (dp[i][j] - 1 == dp[i - 1][j - 1]) {
			ans = A[i] + ans;
			i--; 
			j--;
		}
	}
	cout << dp[lenA-1][lenB-1]<<"\n"<<ans<<"\n";

}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}