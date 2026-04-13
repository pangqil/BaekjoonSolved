#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool bfs(int x, int y, const vector<string>& maps);

//O 빈테이블/ X 파티션/ P 사람
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    
    //vector<vector<bool>> visited(col, vector<bool>(row,false));
    for (const auto& place:places)
    {
        int row=places.size();//5
        int col=places[0].size();//5
        bool safe=true;
       for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                if (place[i][j]=='P')
                {
                    if (!bfs(i,j,place))
                    {
                        safe=false;
                        break;
                    }
                }
            }
            if (!safe) break;
        }
        answer.push_back(safe?1:0);
    }
        
    
    return answer;
}

bool bfs(int x, int y, const vector<string>& map)
{
    int row=map.size();
    int col=map[0].size();
    queue<pair<pair<int,int>,int>> q;//{{x,y},dist}
    q.push({{x,y},0});
    vector<vector<bool>> visited(row, vector<bool>(col,false));
    visited[x][y]=true;
    while(!q.empty())
    {
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int dist=q.front().second;
        
        q.pop();
        
        if (dist>=2) continue;
        
        for(int i=0;i<4;i++)
        {
            int bx=cx+dx[i];
            int by=cy+dy[i];
            
            if (bx>=0&&bx<row&&by>=0&&by<col)
            {
                if (!visited[bx][by]&&map[bx][by]!='X')//벽이라면 아래 방문조차도 안함.
                {
                    if (map[bx][by]=='P') return false;
                    visited[bx][by]=true;
                    q.push({{bx,by},dist+1});
                }
            }
            
            
        }
    }
    return true;
}