#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int u,v,w;
};

#define INF 10000000

int main() {
    int n,m,u,v,w;
    bool flag=false;
    vector<long> dist;
    vector<edge> edges;

    cin>>n>>m;

    edges.push_back({0,0,0});
    dist.resize(n+1,INF);
    dist[1]=0;

    for (int i=1;i<=m;i++) {
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    // 벨만포드 N-1회 완화
    for (int i=1;i<=n-1;i++) {
        for (int j=1;j<edges.size();j++) {
            int cur=edges[j].u;
            int ncur=edges[j].v;
            int cost=edges[j].w;
            if (dist[cur]!=INF && dist[ncur] > dist[cur] + cost) {
                dist[ncur] = dist[cur] + cost;
            }
        }
    }

    // 마지막 검사: 음수 사이클 여부 판단
    for (int j=1;j<edges.size();j++) {
        int cur=edges[j].u;
        int ncur=edges[j].v;
        int cost=edges[j].w;
        if (dist[cur]!=INF && dist[ncur] > dist[cur] + cost) {
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i=2; i<=n; i++) {
        if (dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
