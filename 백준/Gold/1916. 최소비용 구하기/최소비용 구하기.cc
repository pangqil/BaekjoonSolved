#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<vector<pair<int, int>>> v;
vector<int> dist;

int main() {
    int n, m, s, e, c, st, ed;
    cin >> n >> m;

    v.resize(n + 1);
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> c;
        v[s].push_back({e, c});
    }
    cin >> st >> ed;
    dist[st] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, st});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto next : v[now]) {
            int nextNode = next.first;
            int nextCost = cost + next.second;
            if (dist[nextNode] > nextCost) {
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    cout << dist[ed] << "\n";
}
