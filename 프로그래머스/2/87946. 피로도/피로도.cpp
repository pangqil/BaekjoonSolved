#include <string>
#include <vector>

using namespace std;
bool visited[8];
int max_ans=0;
void dfs(int current_k, vector<vector<int>>& dungeons, int count);
//k는 현재 피로도, dungeons[최소피로도, 소모피로도] -> 가장 많은 던전을 탐험할수 있는 최대 카운트
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    dfs(k, dungeons, 0);
    
    answer = max_ans;
    return answer;
}

void dfs(int current_k, vector<vector<int>>& dungeons, int count)
{
    max_ans=max(max_ans, count);
    for (int i=0; i<dungeons.size(); i++)
    {
        if (dungeons[i][0]<=current_k&&visited[i]==false)
        {
            visited[i]=true;
            dfs(current_k-dungeons[i][1], dungeons, count+1);
            visited[i]=false;
        }
    }
}