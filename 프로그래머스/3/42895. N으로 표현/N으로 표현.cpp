#include <string>
#include <vector>

using namespace std;

int mincount=9;
int dp[8];


void dfs(int n, int target, int current, int count)
{
    if (count>8) return;
    if (current==target)
    {
        mincount=min(mincount,count);
        return;
    }
    
    for (int i=1;i<=8;i++)
    {
        int num=dp[i];
        dfs(n,target,current+num,count+i);
        dfs(n,target,current-num,count+i);
        dfs(n,target,current/num,count+i);
        dfs(n,target,current*num,count+i);
    }
    
    
}


int solution(int N, int number) {
    int answer = 0;
    int nn=0;
    for (int i=1;i<=8;i++)
    {
        nn=nn*10+N; 
        dp[i]=nn;
    }
    
    dfs(N, number, 0,0);
    
    if (mincount>8)
    {
        answer=-1;
    }
    else
    {
        answer=mincount;
    }
    
    return answer;
}