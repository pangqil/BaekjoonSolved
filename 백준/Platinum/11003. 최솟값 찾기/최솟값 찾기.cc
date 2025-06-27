#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;
    vector<long long> a(n + 1);
    vector<long long> D(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    deque<int> dq;
    int stidx;
    for (int i = 1; i <= n; i++) {
        stidx=i-l+1;
        while (!dq.empty() && dq.front() < stidx) {//stdix
            dq.pop_front();
        }

        while (!dq.empty() && a[dq.back()] > a[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        D[i] = a[dq.front()];
    }

    for (int i = 1; i <= n; i++) {
        cout << D[i] << " ";
    }

    return 0;
}
