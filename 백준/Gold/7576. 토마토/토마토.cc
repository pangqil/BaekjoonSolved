#include <iostream>
#include <queue>
#include <vector>


using namespace std;




queue<pair<int,int>> q;
vector<vector<int>> mat;

int m,n;
int xdir[4]={-1,1,0,0};
int ydir[4]={0,0,-1,1};
//좌,우,하,상

void bfs();
int days=1;

int main() {

    cin>>m>>n;

    mat.resize(n + 1, vector<int>(m + 1));

    for(int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>mat[i][j];
            if (mat[i][j]==1) {
                q.push(make_pair(i,j));
            }
        }
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] == 0) {
                cout << -1 ;
                return 0;
            }
        }
    }
    cout<<days;

}

//m -> x/ n -> y

void bfs() {

    while (!q.empty()) {
        int size=q.size();
        bool check=false;
        for (int i=0;i<size;i++) {

            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for (int i=0;i<4;i++) {

                int nx=x+xdir[i];
                int ny=y+ydir[i];
                if (nx>=1 && nx<=n && ny>=1 && ny<=m&&mat[nx][ny]==0) {
                    mat[nx][ny]=1;
                    q.push(make_pair(nx,ny));
                    check=true;
                }

            }

        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        if (check) days++;

    }
    days--;

}