#include <iostream>
#include <vector>

using namespace std;

#define INF 100000000

int main() {
    int n,m,u,v,w;

    vector<vector<int>> edge;
    cin>>n>>m;
    edge.resize(n+1);
    for (int i=1;i<=n;i++) {
        edge[i]=vector<int>(n+1,INF);
        edge[i][i]=0;
    }

    for (int i=1;i<=m;i++) {
        cin>>u>>v>>w;
        if (edge[u][v] > w) { 
            edge[u][v] = w;
        }
    }

    for (int i=1;i<=n;i++) {//mid
        for (int j=1;j<=n;j++) {//u
            for (int k=1;k<=n;k++) {//v
                if (edge[j][k]>edge[j][i]+edge[i][k])
                    edge[j][k]=edge[j][i]+edge[i][k];
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (edge[i][j]==INF) {
                cout<<"0 ";
            }
            else {

                cout<<edge[i][j]<<" ";
            }
        }
        cout<<"\n";
    }


}