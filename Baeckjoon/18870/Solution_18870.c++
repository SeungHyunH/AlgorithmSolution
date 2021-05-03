#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

void solution() {
    int N;
    cin >> N;
    vector<int> vec, data;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
        data.push_back(x);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (int i : data) {
        cout << lower_bound(vec.begin(), vec.end(), i) - vec.begin()<<' ';
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution();
    return 0;
}