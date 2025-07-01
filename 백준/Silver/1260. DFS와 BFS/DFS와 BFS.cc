#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> ve;
vector<int> visited;
vector<int> visitedq;
queue<int> q;

void DFS(int v);
void BFS(int v);

int main() {
    int n,m,v,s,e;
    cin>>n>>m>>v;
    ve.resize(n+1);
    visited.resize(n+1, false);
    visitedq.resize(n+1, false);
    for (int i = 0; i < m; i++) {
        cin>>s>>e;
        ve[s].push_back(e);
        ve[e].push_back(s);
    }
    for (int i=0;i<=n;i++) {
        sort(ve[i].begin(),ve[i].end());
    }
    DFS(v);
    cout<<"\n";
    BFS(v);
}

void DFS(int v) {
    visited[v] = 1;
    cout<<v<<" ";
    for (int k:ve[v]) {
        if (!visited[k]) {
            DFS(k);

        }
    }
    //visited[v] = 0;
}
void BFS(int v) {
    q.push(v);
    visitedq[v] = true;

    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for (int k:ve[cur]) {
            if (!visitedq[k]) {
                visitedq[k] = true;
                q.push(k);
            }
        }
    }
}