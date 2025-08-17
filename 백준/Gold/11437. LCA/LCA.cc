#include <iostream>
#include <vector>
using namespace std;

#define MAX 20

vector<vector<int>> adj;
vector<vector<int>> parent;
vector<int> vdepth;

void dfs(int cur, int par) {
    vdepth[cur] = vdepth[par] + 1;
    parent[cur][0] = par;
    for (auto next : adj[cur]) {
        if (next != par) dfs(next, cur);
    }
}

void init(int n) {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

int lca(int u, int v) {
    if (vdepth[u] < vdepth[v]) swap(u, v);

    int df = vdepth[u] - vdepth[v];
    for (int i = 0; df; i++) {
        if (df % 2) u = parent[u][i];
        df /= 2;
    }

    if (u == v) return u;

    for (int i = MAX - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.resize(n + 1);
    parent.resize(n + 1, vector<int>(MAX, 0));
    vdepth.resize(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    dfs(1, 1); 
    init(n);

    int rn;
    cin >> rn;
    for (int i = 0; i < rn; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << " ";
    }
    cout << "\n";
}
