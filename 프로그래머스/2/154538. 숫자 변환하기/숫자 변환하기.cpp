#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
//x에서 y를 만들기
//n을 더하거나, 2or3을 곱하는 선택지

int bfs(int x, int y, int n);
int solution(int x, int y, int n) {
    int answer = 0;
    answer=bfs(x,y,n);
    
    return answer;
}

int bfs(int x, int y, int n)
{
    queue<pair<int,int>> q;//number,count
    vector<bool> visit;
    visit.resize(1000001,false);
    q.push({x,1});
    visit[x]=true;
    while (!q.empty())
    {
        auto x=q.front();
        q.pop();
        if (x.first==y) return x.second-1;
        if (x.first+n<=y&&visit[x.first+n]==false)
        {
            q.push({x.first+n,x.second+1});
            visit[x.first+n]=true;
        }
            
        if (x.first*2<=y&&visit[x.first*2]==false)
        {
            q.push({x.first*2,x.second+1});
            visit[x.first*2]=true;
        }
        if (x.first*3<=y&&visit[x.first*3]==false)
        {
            q.push({x.first*3,x.second+1});
            visit[x.first*3]=true;
        }
    }
    return -1;
}