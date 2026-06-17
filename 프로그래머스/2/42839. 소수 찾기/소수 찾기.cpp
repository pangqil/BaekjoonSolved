#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool visit[7]={false};
map<int, bool> v;
int ans=0;

bool IsPrime(int n)
{
    if (n==1||n==0) return false;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0) return false;
    }        
    return true;
}

void dfs(string current, string numbers)
{
    
    for (int i=0;i<numbers.length();i++)
    {
        if (visit[i]==true) continue;
        
        visit[i]=true;
        string cur=current+numbers[i];
        if (IsPrime(stoi(cur))&&v[stoi(cur)]==false)
        {
            v[stoi(cur)]=true;
            ans++;
        } 
            
        dfs(current+numbers[i],numbers);
        visit[i]=false;
    }
}

int solution(string numbers) {
    
    dfs("",numbers);
    return ans;
}
