#include <iostream>
#include <vector>

using namespace std;

vector<int> vr;

int n, m, a, b;
bool flag;

int find(int a) {
    if (vr[a] == a) return a;
    return vr[a] = find(vr[a]); 
}

void aunion(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (a > b) swap(a, b);
        vr[b] = a;
    }
}

void isunion(int a, int b) {
    if (find(a) == find(b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);           

    cin >> n >> m;
    vr.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        vr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> flag >> a >> b;
        if (flag == 0) {
            aunion(a, b);
        } else {
            isunion(a, b);
        }
    }
}
