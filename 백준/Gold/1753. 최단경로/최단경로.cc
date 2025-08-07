#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 99999999

vector<vector<pair<int,int>>> edge;
vector<int> D;

void djkstra(int start);
int main() {
    int V,E,K;
    int u,v,w;

    cin>>V>>E>>K;


    edge.resize(V+1);
    D.resize(V+1, INF);
    for(int i=0;i<E;i++) {
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    D[K]=0;
    djkstra(K);

    for (int i=1;i<=V;i++) {
        if (D[i]==INF) {
            cout<<"INF\n";
        }
        else {
            cout<<D[i]<<"\n";
        }
    }
}

void djkstra(int start) {
    priority_queue<pair<int,int>> q;

    q.push({0,start});
    while(!q.empty()) {
        int cost=-q.top().first;
        int cur=q.top().second;
        q.pop();

        if (D[cur]<cost) continue;

        for (auto p: edge[cur]){
            int ncur=p.first;
            int ncost=p.second;
            if (D[ncur]>D[cur]+ncost) {
                D[ncur]=D[cur]+ncost;
                q.push({-D[ncur],ncur});
            }
        }


    }
}