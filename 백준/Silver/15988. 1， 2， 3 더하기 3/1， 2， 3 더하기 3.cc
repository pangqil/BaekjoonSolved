#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    vector<int> vc(1000001);
    vector<int> re;

    vc[0] = 1;  
    vc[1] = 1;
    vc[2] = 2;
    vc[3] = 4;

    for (int i = 4; i <= 1000000; i++) {
        vc[i] = ((long long)vc[i - 1] + vc[i - 2] + vc[i - 3]) % 1000000009;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        re.push_back(k);
    }

    for (int t : re) {
        cout << vc[t] << '\n';
    }

    return 0;
}
