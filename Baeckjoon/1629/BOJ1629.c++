#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 2187+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll mypow(ll a, ll b, ll c) {
	if (b == 1) { return a % c; }
	else {
		ll result = mypow(a, b / 2, c);
		if (b % 2 == 0)
			return (result * result) % c;
		else
			return ((result * result) % c * a) % c;
	}
}

void solution() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << mypow(a, b, c);
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}