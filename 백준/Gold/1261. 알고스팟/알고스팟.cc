#include <deque>
#include <iostream>
#include <vector>

using namespace std;


#define MAX 1e9
int n,m;
int final=MAX;
vector<vector<int>> mt;
vector<vector<int>> visit;
vector<vector<int>> dist;

void dfs(int x, int y, int count);
void bfs();

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>m>>n;
    string s;

    mt.resize(n, vector<int>(m,0));
    dist.resize(n, vector<int>(m,MAX));
    visit.resize(n, vector<int>(m,0));
    for (int i=0;i<n;i++) {
        cin>>s;
        for (int j=0;j<m;j++) {
           mt[i][j]=s[j]-48;
        }
    }
    //dfs(0,0,0);
    //cout<<final;
    bfs();
    cout<<dist[n-1][m-1];
}

void dfs(int x, int y, int count) {
    if (x==n-1&&y==m-1) {
        final=min(final,count);
        return;
    }
    int xpos[4] = {0,0,1,-1};
    int ypos[4] = {1,-1,0,0};
    visit[x][y]=1;
    for (int i=0;i<4;i++) {
        int newx=xpos[i]+x;
        int newy=ypos[i]+y;
        if (newx<0||newx>=n||newy<0||newy>=m) {continue;}
        if (visit[newx][newy]==1) {continue;}
        if (count>101){continue;}
        dfs(newx,newy,count+(mt[newx][newy]==1));
    }
    visit[x][y]=0;

}
//n,m으로 이동해야 되는데...
//dfs를 써서 n,m으로 이동하는 루트 여러개를 발견할 수 있음.
//해당 루트에서 만약 1을 만날경우 +하기.
//그중 min을 찾기
void bfs() {
    deque<pair<int,int>> q;
    q.push_back({0,0});
    dist[0][0]=0;

    int xpos[4] = {0,0,1,-1};
    int ypos[4] = {1,-1,0,0};

    while (!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop_front();
        for (int i=0;i<4;i++) {
            int newx=xpos[i]+cur.first;
            int newy=ypos[i]+cur.second;
            if (newx<0 || newx>=n || newy<0 || newy>=m) continue;

            int cost=dist[cur.first][cur.second]+mt[newx][newy];
            if (cost<dist[newx][newy]) {
                dist[newx][newy]=cost;
                if (mt[newx][newy]==1) {
                    q.push_back({newx,newy});
                }
                else {
                    q.push_front({newx,newy});
                }
            }
        }
    }

}