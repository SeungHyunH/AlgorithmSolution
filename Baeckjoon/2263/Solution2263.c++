#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define MAX 100000+1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int N;
int inorder[MAX];
int postorder[MAX];

void preorder(int is, int ie, int ps, int pe) {
	if (is >= ie) { return; }
	int f = postorder[pe - 1];
	cout <<f<<" ";

	int t = inorder[f], d = t - is;
	preorder(is, t, ps, ps + d);
	preorder(t + 1, ie, ps + d, pe - 1);
}

void solution() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		inorder[temp]=i;
	}
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}

	preorder(0, N, 0, N );
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}