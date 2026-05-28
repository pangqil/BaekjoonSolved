#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int answer=0;
int bfs(vector<vector<pair<int,int>>> edge, int N, int K);

int solution(int N, vector<vector<int>> road, int K) {

    
    vector<vector<pair<int,int>>> edge(N+1);
    for (int i=0;i<road.size();i++)
    {
        int u=road[i][0];
        int v=road[i][1];
        int w=road[i][2];
        
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }
    return bfs(edge, N,K);
}

int bfs(vector<vector<pair<int,int>>> edge, int N, int K)
{
    vector<int> dist(N+1,1e9);
    queue<pair<int,int>> q;
    
    q.push({1,0});
    dist[1]=0;
    
    while (!q.empty())
    {
        auto cur=q.front();
        q.pop();
        
        int curs=cur.first;
        int curw=cur.second;
        
        if (dist[curs]<curw) continue;
        
        for (auto next:edge[curs])
        {
            int weight=next.second+curw;
            if (weight<=K&&weight<dist[next.first])//다음지역이 더 넣어도 되면
            {
                dist[next.first]=weight;
                q.push({next.first,weight});
            }
        }
    }
    for (int i=1;i<=N;i++)
    {
        if (dist[i]<=K)
        {
            answer++;
        }
    }
    return answer;
}