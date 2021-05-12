#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define pii pair<int,int>
#define MAX 4000001
#define INF 987654321
using namespace std;

int n;
vector<bool>check;
vector<int>arr;

void solution() {
	cin >> n;

	check.resize(n+1, true);//에라토스테네스의 체
    for (int i = 2; i * i <= n; i++)
    {
        if (!check[i]) continue;
        for (int j = i * i; j <= n; j += i)
        {
            check[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (check[i]) arr.push_back(i);
    }

    int ans = 0, l = 0, r = 0, sum = 0;
    while (1) {
        if (sum >= n) {
            sum -= arr[l++];
        }
        else if(r==arr.size()){
            break;
        }
        else {
            sum += arr[r++];
        }
        if (sum == n) { ans++; }
    }
    cout << ans << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}