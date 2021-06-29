#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 100+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;


matrix operator*(const matrix& a, const matrix& b) {
	matrix res(a.size(), vector<ll>(a.size()));
	for (ll i = 0; i < a.size(); i++) {
		for (ll j = 0; j < b[0].size(); j++) {
			for (ll k = 0; k < a[0].size(); k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000000007;
		}
	}
	return res;
}

matrix mypow(matrix a, ll n) {
	ll size = a.size();
	matrix res(size, vector<ll>(size));
	for (ll i = 0; i < size; i++) { // 단위 행렬
		res[i][i] = 1;
	}
	while (n > 0) {
		if (n % 2 == 1) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}

void solution() {
	ll n;
	cin >> n;
	matrix a = { {1, 1}, {1, 0} };
	matrix res = (mypow(a, n - 1));
	cout << (res[1][0] + res[1][1]) % 1000000007;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout.precision(1);
	//cout << fixed;
	solution();
	return 0;
}