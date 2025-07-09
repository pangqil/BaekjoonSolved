#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> av(n);
    vector<int> bv(n);

    for (int i = 0; i < n; i++) cin >> av[i];
    for (int i = 0; i < n; i++) cin >> bv[i];

    sort(av.begin(), av.end());              // A 오름차순
    sort(bv.begin(), bv.end(), greater<>()); // B 내림차순

    int result = 0;
    for (int i = 0; i < n; i++) {
        result += av[i] * bv[i];
    }

    cout << result;
}
