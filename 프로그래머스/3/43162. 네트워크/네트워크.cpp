#include <vector>

using namespace std;

void dfs(int currentcomputers, const vector<vector<int>>& computers, vector<bool>& visit, int totalcom)
{
    visit[currentcomputers]=true;
    for (int ncomputer = 0; ncomputer< totalcom; ++ncomputer)
    {
        if (computers[currentcomputers][ncomputer]==1&&!visit[ncomputer])
        {
            dfs(ncomputer, computers, visit, totalcom);
        }
    }
}
int solution(int n, vector<vector<int>> computers)
{
    int netcount = 0;
    vector<bool> visit(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!visit[i])
        {
            dfs(i, computers, visit, n);
            netcount++;
        }
    }
    return netcount;
}