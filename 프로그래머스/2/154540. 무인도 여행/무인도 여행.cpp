#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int bfs(int x, int y, vector<string>& maps, vector<vector<bool>>& visited);

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int col=maps.size();
    int row=maps[0].size();
    vector<vector<bool>> visited(col,vector<bool>(row,false));
    
    for (int i=0;i<col;i++)
    {
        for (int j=0;j<row;j++)
        {
            if (visited[i][j]==false && maps[i][j]!='X')
            {
                answer.push_back(bfs(i,j,maps,visited));
            }
        }
    }
    sort(answer.begin(),answer.end());
    if (answer.empty()) answer.push_back(-1);
    return answer;
}

int bfs(int x, int y, vector<string> &maps, vector<vector<bool>>& visited)
{
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y]=true;
    int sum=0;
    
    while(!q.empty())
    {
        // pair<int,int> cur=q.front();
        // int cx=cur.first;
        // int cy=cur.second;
        auto [cx,cy]=q.front();
        q.pop();
        sum+=static_cast<int>(maps[cx][cy]-'0');
        
        for (int i=0;i<4;i++)
        {
            int bx=cx+dx[i];
            int by=cy+dy[i];
            if (bx>=0 && by>=0 && bx<maps.size() && by<maps[0].size())
            {
                if (visited[bx][by]==false && maps[bx][by]!='X')
                {
                    visited[bx][by]=true;
                    q.push({bx,by});
                }
            }
        }
    }
    return sum;
}
