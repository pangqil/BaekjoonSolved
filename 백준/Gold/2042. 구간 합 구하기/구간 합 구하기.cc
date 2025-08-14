#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
vector<long long> tree;
int tree_size, tree_height, st;

void maketree() {
    for (int i = 1; i <= tree_size; i++)
        tree[st + i-1] = v[i];

    for (int i = st - 1; i > 0; i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
}

void updatetree(int b, long long c) {
    int i = st + b - 1;
    tree[i] = c;
    while (i > 1) {
        i /= 2;
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

long long sumtree(int l, int r) {
    l += st-1;
    r += st-1;
    long long res = 0;
    while (l <= r) {
        if (l % 2 == 1) res += tree[l++];
        if (r % 2 == 0) res += tree[r--];
        l /= 2;
        r /= 2;
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    v.resize(n+1);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    // 트리 초기화
    tree_size = n;
    tree_height = (int)ceil(log2(tree_size));
    st = 1 << tree_height;
    tree.resize(st * 2);

    maketree();

    for (int i = 0; i < m + k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            updatetree(b, c);
        } else if (a == 2) {
            cout << sumtree(b, c) << "\n";  //
        }
    }
    return 0;
}
