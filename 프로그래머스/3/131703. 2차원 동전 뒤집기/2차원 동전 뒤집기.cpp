#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//8:00


vector<vector<int>> targetboard;
int mincount=10000;

bool ispsame(vector<vector<int>> cur,vector<vector<int>> target, int col)
{
    for (int i=0;i<cur.size();i++)
    {
        if (cur[i][col]!=target[i][col]) return false;
    }
    return true;
}

bool ispreverse(vector<vector<int>> cur,vector<vector<int>> target, int col)
{
    for (int i=0;i<cur.size();i++)
    {
        if (cur[i][col]==target[i][col])  return false;
    }
    return true;
}


void flip(vector<vector<int>>& selected, int row)
{
    for (int i=0;i<selected[row].size();i++)
    {
        if (selected[row][i]==1) selected[row][i]=0;
        else selected[row][i]=1;
    }
}

void dfs(int row, vector<vector<int>> curboard, int rowcount)
{
    if (row==curboard.size())
    {
        int ccount=0;
        bool possible=true;
        
        for (int i=0;i<curboard[0].size();i++)
        {
            if (ispsame(curboard,targetboard,i))
            {
                continue;
            }
            if (ispreverse(curboard,targetboard,i))
            {
                ccount++;
            }    
            else
            {
                possible=false;
                break;
            }
        }
    
        if (possible)
        {
            mincount=min(rowcount+ccount,mincount);
        }
        return;
    }
    
    dfs(row+1, curboard, rowcount);
    flip(curboard, row);
    dfs(row+1, curboard, rowcount+1);
    
}


int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    targetboard=target;
    mincount=10000;
    
    dfs(0, beginning, 0);
    
    if (mincount==10000) return -1;
    
    
    
    answer=mincount;
    return answer;
}

int main()
{
    vector<vector<int>> b={
        
            {0, 1, 0, 0, 0}, 
            {1, 0, 1, 0, 1},
            {0, 1, 1, 1, 0}, 
            {1, 0, 1, 1, 0}, 
            {0, 1, 0, 1, 0}
            
    };
    vector<vector<int>> t={
        
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 0, 1},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0}, 
            {0, 0, 0, 0, 1}
            
    };
    
    cout<<solution(b,t);
}
