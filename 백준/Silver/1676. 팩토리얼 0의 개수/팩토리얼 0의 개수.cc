#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    int result = 0;
    for (int i = 5; k / i >= 1; i *= 5) {
        result += k / i;
    }

    cout << result << endl;
    return 0;
}
