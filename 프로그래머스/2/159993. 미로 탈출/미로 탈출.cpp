#include <iostream>
#include <ostream>
#include <queue>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int visit[100][100];
int dist[100][100];

int SX,SY;
int LX,LY;
int EX,EY;
int fdist=0;
int sdist=0;

int bfs(int sx, int sy, int ex, int ey, vector<string> maps)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{sx,sy},0});
    visit[sx][sy]=1;
    
    while (!q.empty())
    {
        auto f=q.front();
        q.pop();
        
        int cx=f.first.first;
        int cy=f.first.second;
        int depth=f.second;
        
        if (cx==ex&&cy==ey)
        {
            return depth;
        }
        
        for (int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
        
            if (nx<0||nx>=maps.size()||ny<0||ny>=maps[0].size()) continue;
            if (visit[nx][ny]==true) continue;
            if (maps[nx][ny]=='X') continue;
            q.push({{nx,ny},f.second+1});
            visit[nx][ny]=true;
        }
    }
    return -1;
}

int solution(vector<string> maps)
{
    for (int i=0;i<maps.size();i++)
    {
        for (int j=0;j<maps[i].size();j++)
        {
            if (maps[i][j]=='S')
            {
                SX=i;
                SY=j;
            }
            if (maps[i][j]=='L')
            {
                LX=i;
                LY=j;
            }
            if (maps[i][j]=='E')
            {
                EX=i;
                EY=j;
            }
        }
    }
    memset(visit,0,sizeof(visit));
    fdist=bfs(SX,SY,LX,LY,maps);
    memset(visit,0,sizeof(visit));
    sdist=bfs(LX,LY,EX,EY,maps);
    if (fdist<0||sdist<0) return -1;
    
    return fdist+sdist;
}

int main()
{
    solution(	{"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"});
}
