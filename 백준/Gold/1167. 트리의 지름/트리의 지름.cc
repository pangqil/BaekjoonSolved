#include <iostream>
#include <vector>

using namespace std;

int v;
int maxd = 0;
int far_node = 0;
vector<vector<pair<int, int>>> tr;
vector<bool> visit;

void dfs(int curr, int depth) {
    visit[curr] = true;
    if (depth > maxd) {
        maxd = depth;
        far_node = curr;
    }

    for (auto [next, weight] : tr[curr]) {
        if (!visit[next]) {
            dfs(next, depth + weight);
        }
    }
}

int main() {
    cin >> v;
    tr.resize(v + 1);
    visit.resize(v + 1, false);

    int fv, sv, d;
    for (int i = 0; i < v; ++i) {
        cin >> fv;
        while (true) {
            cin >> sv;
            if (sv == -1) break;
            cin >> d;
            tr[fv].push_back({sv, d});
        }
    }
    
    dfs(1, 0);
    
    fill(visit.begin(), visit.end(), false);
    maxd = 0;
    dfs(far_node, 0);

    cout << maxd << endl;
}
