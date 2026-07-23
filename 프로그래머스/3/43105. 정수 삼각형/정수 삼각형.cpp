#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    vector<vector<int>> dp=triangle;
    for (int i=1;i<triangle.size();i++)
    {
        for (int j=0;j<triangle[i].size();j++)
        {
            if (j==0)//start라면
            {
                dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
            }
            else if(j==triangle[i].size()-1)//end라면
            {
                dp[i][j]+=dp[i-1][j-1];
            }
            else//그 사이라면
            {
                dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    
    int lastsize=triangle[triangle.size()-1].size();
    int maxcount=0;
    for (int j=0;j<lastsize;j++)
    {
        maxcount=max(maxcount,dp[triangle.size()-1][j]);
    }
    return maxcount;
}