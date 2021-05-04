#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

int Data[MAX]{ 0, };
int dp[MAX]{ 0, };
int answer[MAX];
vector<int>ans;
void print(int index) {
	if (index != -1) { ans.push_back(Data[index]); print(answer[index]); }
}

void solution() {
	int N;
	cin >> N;
	int Max = 0;
	fill(answer, answer + N, -1);
	for (int i = 0; i < N; i++) { cin >> Data[i]; dp[i] = 1; }
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (Data[j] < Data[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				answer[i] = j;
			}
		}
		if (dp[Max] < dp[i]) { Max = i; }
	}
	cout << dp[Max] << "\n";
	print(Max);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) { cout << ans[i] << " "; }
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}