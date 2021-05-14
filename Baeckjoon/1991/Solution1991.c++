#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define MAX 26 + 1
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int N;
pii arr[MAX];

void Preorder(int start) {
	cout << (char)(start+65);
	int l = arr[start].first;
	int r = arr[start].second;
	if (l >= 0) { Preorder(l); }
	if (r >= 0) { Preorder(r); }
}

void Inorder(int start) {
	int l = arr[start].first;
	int r = arr[start].second;
	if (l >= 0) { Inorder(l); }
	cout << (char)(start+65);
	if (r >= 0) { Inorder(r); }
}

void Postorder(int start) {
	int l = arr[start].first;
	int r = arr[start].second;
	if (l >= 0) { Postorder(l); }
	if (r >= 0) { Postorder(r); }
	cout << (char)(start + 65);
}

void solution() {
	cin >> N;
	for (int i = 0; i < N; i++) { 
		char parent, child_left, child_right;
		cin >> parent>>child_left>>child_right;
		arr[parent - 'A']={ child_left - 'A',child_right - 'A' };
	}
	Preorder(0);
	cout << "\n";

	Inorder(0);
	cout << "\n";

	Postorder(0);
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}