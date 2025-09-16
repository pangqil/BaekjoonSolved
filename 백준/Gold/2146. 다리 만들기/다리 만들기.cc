#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//합집합으로 섬 넘버를 분류
//각 합집합은 1,2,3...max로 이루어짐.
//bfs에서 뻗어나온 곳이 1이되, 자신의 합집합이 아니라면 min기록
int n;
int island_num=2;

vector<vector<int>> v;
vector<vector<int>> island;
vector<vector<int>> visit;
vector<vector<int>> visitq;
vector<int> islandvisit;

#define INF 1e9

int outputdepth=INF;

void dfs(int x, int y);
void bfs(int x, int y);

int main() {

    cin>>n;

    v.resize(n, vector<int>(n, 0));
    island.resize(n, vector<int>(n, 0));
    visit.resize(n, vector<int>(n, 0));
    visitq.resize(n, vector<int>(n, 0));

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>v[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (v[i][j]==0||visit[i][j]==1) continue;
            dfs(i,j);
            island_num++;
        }
    }
    islandvisit.resize(island_num+1, 0);

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (v[i][j]==1) {//섬이라면
                int id=island[i][j];
                if (islandvisit[id]){ continue;}//이미 검사했다면 continue
                bfs(i,j);
                islandvisit[id]=1;
            }

        }
    }
    cout<<outputdepth;

}

void dfs(int x, int y) {
    island[x][y]=island_num;
    visit[x][y]=1;

    int xpos[4]={0,0,1,-1};
    int ypos[4]={1,-1,0,0};

    for (int i=0;i<4;i++) {
        int newx=xpos[i]+x;
        int newy=ypos[i]+y;
        if (newx<0 || newx>=n || newy<0 || newy>=n) {continue;}
        if (v[newx][newy]==1&&visit[newx][newy]==0) {//방문안한 육지라면 1.방문처리하고 2.인덱스로 덮기.
            dfs(newx,newy);
        }
    }
}

void bfs(int x, int y) {
    int xpos[4]={0,0,1,-1};
    int ypos[4]={1,-1,0,0};

    queue<pair<pair<int,int>, int>> q;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            visitq[i][j]=0;//visitq를 초기화 하고...
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (island[i][j]==island[x][y]) {//모든 같은섬을 방문처리하고 push하기
                q.push({{i,j},0});
                visitq[i][j]=1;
            }
        }
    }

    while (!q.empty()) {
        pair<pair<int,int>, int> p = q.front();
        int posx=p.first.first;
        int posy=p.first.second;
        int depth=p.second;

        q.pop();

        for (int i=0;i<4;i++) {//상하좌우 push
            int newx=xpos[i]+posx;
            int newy=ypos[i]+posy;

            if (newx<0 || newx>=n || newy<0 || newy>=n||visitq[newx][newy]==1) {continue;}//벗어날 경우 스킵
            if (v[newx][newy]==1&&island[newx][newy]!=island[x][y]) {//육지면서, 자신과 다른 육지라면 depth 출력
                outputdepth=min(depth,outputdepth);
                return;
            }
            if (v[newx][newy]==0){//얘가 바다라면 depth+1
                q.push({{newx,newy},depth+1});
                visitq[newx][newy]=1;
            }
        }

    }


}