#include <queue>
#include <string>
#include <vector>

using namespace std;

int cuttree(int n, int start, int u, int v, vector<vector<int>>& graph)
{
    vector<bool> visit(n+1, false);
    queue<int> q;
    
    visit[start] = true;
    int count=0;
    
    q.push(start);
    
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        count++;
        
        for (int next:graph[cur])
        {
            if (visit[next]==false)
            {
                if ((cur==u&&next==v)||(cur==v&&next==u)) continue;
                q.push(next);
                visit[next]=true;
            }
        }
    }
    return count;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    vector<vector<int>> graph(n+1);
    
    for (auto w:wires)
    {
        int u=w[0];
        int v=w[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (const auto& w:wires)
    {
        int u=w[0];
        int v=w[1];
        
        int asize=cuttree(n,1, u,v,graph);
        int bsize=n-asize;
        
        int diff=abs(asize-bsize);
        answer=min(answer, diff);
    }
    
    
    return answer;
}

//모든게 연결된 그래프를 만들고, 한 그래프 삭제해서 bfs하기
//각 하나씩 끊었을때 차이의 갯수가 min이 되는 점을 캐치하라!