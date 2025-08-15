#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> tree;
int st;
int n, m;

void maketree() {
    for (int i = 1; i <= n; i++) {
        tree[i + st - 1] = v[i];
    }
    for (int i = st - 1; i > 0; i--) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
}

int mintree(int l, int r) {
    l += st - 1;
    r += st - 1;
    int minn = 1000000001; // 최댓값보다 큰 값으로 초기화
    while (l <= r) {
        if (l % 2 == 1) {
            minn = min(minn, tree[l]);
            l++;
        }
        if (r % 2 == 0) {
            minn = min(minn, tree[r]);
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return minn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v[i] = x;
    }

    int treeheight = ceil(log2(n));
    st = 1 << treeheight;
    tree.resize(2 * st, 1000000001); 
    maketree();

    for (int k = 0; k < m; k++) {
        int a, b;
        cin >> a >> b;
        cout << mintree(a, b) << "\n";
    }
    return 0;
}