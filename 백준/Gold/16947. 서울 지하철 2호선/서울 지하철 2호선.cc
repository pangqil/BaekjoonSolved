#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> m;
vector<int> visit;
vector<int> onstack;
vector<int> parent;
vector<bool> unionp;

int n;
void dfs(int u, int p);
void bfs(int u);

int cycles=-1;
int cyclee=-1;


int main() {

    cin>>n;

    int u,v;


    m.resize(n+1);
    parent.resize(n+1);
    onstack.resize(n+1);
    visit.resize(n+1,0);
    unionp.resize(n+1,false);

    for (int i=1;i<=n;i++) {
        cin>>u>>v;
        m[u].push_back(v);
        m[v].push_back(u);
    }

    dfs(1,0);//사이클을 발견한다.

    if(cycles!=-1){
        int current=cyclee;
        while(current!=cycles){
            unionp[current]=true;
            current=parent[current];
         }
        unionp[cycles]=true;
    }

    bfs(1);

}
//123451

void dfs(int u, int p) {
    visit[u]=1;
    parent[u]=p;

    for (int nextcur:m[u]) {
        if(nextcur==p) continue;
        if (visit[nextcur]==0) {
            dfs(nextcur, u);
            if(cycles!=-1) return;
        }
        else if (visit[nextcur]==1&& cycles==-1) {
                cycles=nextcur;
                cyclee=u;
                return;
        }
    }

}

void bfs(int k) {
    queue<pair<int,int>> q;
    vector<int> dist(n+1, -1);
    for(int i=1;i<=n;i++){
        if(unionp[i]==1){
            q.push({i,0});
            dist[i]=0;
        }
    }
    while(!q.empty()) {
        auto [u,d]=q.front();
        q.pop();
        for(int v:m[u]) {
            if(dist[v]==-1){
                dist[v]=d+1;
                q.push({v,d+1});    }
    }

    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}