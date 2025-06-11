#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t, p;

    cin >> n;
    vector<int> dp(n + 2, 0); 
    vector<int> T(n + 1, 0);
    vector<int> P(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        T[i] = t;
        P[i] = p;
    }

    for (int i = n; i > 0; i--) {
        if ((T[i] + i) > n + 1) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        }
    }

    cout << dp[1]; 
    return 0;
}
