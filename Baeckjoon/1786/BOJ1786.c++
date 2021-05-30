#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define MAX 10000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string t, p;
vector<int> ans;

vector<int> Fail(string p) {
	int m = p.length();
	vector<int> pi(m);

	int begin = 1;
	int matched = 0;
	pi[0] = 0;
	while (begin + matched < m) {
		if (p[begin + matched] == p[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

void KMP() {
	int m = p.length();
	int n = t.length();
	vector<int>pi = Fail(p);

	int begin = 0;
	int matched = 0;
	while (begin + m <= n) {
		if (matched < m && t[begin + matched] == p[matched]) {
			matched++;

			if (matched == m)
				ans.push_back(begin + 1);
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

void solution() {
	getline(cin, t);
	getline(cin, p);
	KMP();
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout << fixed;
	//cout.precision(2);
	solution();
	return 0;
}