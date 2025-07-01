#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vl;
vector<bool> visited;

bool arrive=false;
void DFS(int n,int depth);


int main() {

    int n,m;
    int a,b;
    cin>>n>>m;

    vl.resize(n);
    visited.resize(n, false);
    for (int i=0;i<m;i++) {
        cin>>a>>b;
        vl[a].push_back(b);
        vl[b].push_back(a);
    }

    for (int i=0;i<n;i++) {
        DFS(i, 0);
    }
    cout<<arrive<<endl;
}


void DFS(int n, int depth) {
    if (arrive) return;
    if (depth==4) {
        arrive=true;
        return;
    }
    visited[n]=true;
    for (int k:vl[n]) {
        if (!visited[k]) {
            DFS(k,depth+1);
        };
    }
    visited[n]=false;
}
