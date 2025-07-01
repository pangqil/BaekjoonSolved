#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int,int>> q;
vector<vector<int>> maze;
int n,m;
int depth=0;

void BFS();

int main() {
    cin>>n>>m;
    maze.resize(n+1);
    for (int i=1;i<=n;i++) {
        string mazst;
        cin>>mazst;
        maze[i].push_back(  10);
        for (int j=1;j<=m;j++) {
            maze[i].push_back(int(mazst[j-1])-48);
        }
        mazst.clear();
    }
    BFS();

    cout<<maze[n][m]<<endl;

}

void BFS() {
 int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    //up,down,right,left
    q.push({1,1});
    while (!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (nx<=n&&nx>=1&&ny>=1&&ny<=m) {
                if (maze[nx][ny]==1) {
                    maze[nx][ny]=maze[x][y]+1;
                    q.push({nx,ny});

                }
            }
        }
    }

}