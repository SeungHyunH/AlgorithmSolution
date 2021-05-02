#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

void solution() {
	int N,num;
	cin >> N;
	priority_queue<int>MaxQ;
	priority_queue<int, vector<int>, greater<int>>MinQ; //priority_queue<int> MinQ; 해서 넣을 때 -를 곱해서 넣어서 구현하는 방법도 있음
	for (int i = 1; i <= N; i++) {
		cin >> num;
		if (MaxQ.size()!=MinQ.size()) {
			MinQ.push(num);
		}
		else {
			MaxQ.push(num);
		}
		if (!MaxQ.empty() && !MinQ.empty() && MinQ.top() < MaxQ.top()) {
			int maxvalue = MaxQ.top();
			int minvalue = MinQ.top();
			MaxQ.pop();
			MinQ.pop();
			MaxQ.push(minvalue);
			MinQ.push(maxvalue);
		}
		cout << MaxQ.top() << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution();
	return 0;
}