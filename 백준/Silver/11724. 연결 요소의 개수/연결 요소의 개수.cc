#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n,m,u,v;
vector<int> visited;
vector<vector<int>> edge;
void DFS(int v);

int main() {

    cin>>n>>m;
    edge.resize(n+1);
    visited.resize(n+1,0);
    for (int i=1;i<=m;i++) {
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int count=0;
    for (int i=1;i<=n;i++) {
        if (visited[i]==0) {
            count++;
            DFS(i);
        }//연관된 컴포넌트 전부 탐색
    }
    cout<<count<<endl;
}

void DFS(int v) {
    if (visited[v]==1) return;
    visited[v]=1;//1-2,3,5면 2,3,5 연결된거 전부 방문처리.
    for (int i:edge[v]) {
        if (visited[i]==0) {
            DFS(i);
        }
    }
}