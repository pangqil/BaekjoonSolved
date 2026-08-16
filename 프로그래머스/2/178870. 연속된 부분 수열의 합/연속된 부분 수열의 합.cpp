#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//12시 39분
//부분순열이고, sum은 k
//길이가 짧은거 우선
//길이가 짧다면, 시작인덱스가 작아야 함.
vector<int> sequnces; 
vector<pair<int,int>> arrs;
int target;

bool compare(const pair<int,int> &a, const pair<int,int> &b)
{
    int alen=a.second-a.first;
    int blen=b.second-b.first;
    
    if (alen==blen)
    {
        return a.first<b.first;
    }
    else
    {
        return alen<blen;
    }
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    sequnces=sequence;
    target=k;
    
    int lidx=0;
    int ridx=0;
    int sum=sequence[0];
    
    while (lidx<=ridx&&ridx<=sequnces.size()-1)
    {
        if (target==sum)
        {
            arrs.push_back({lidx,ridx});
            sum-=sequnces[lidx];
            lidx++;
        }
    
        if (sum>target)
        {
            sum-=sequnces[lidx];
            lidx++;
            
            // dfs(sum+sequnces[idx+1], idx+1, lidx, ridx);
            // dfs(sum, idx+1,lidx, ridx);
        }
        else if (target>sum)
        {
            //sequnces.size()=5
            //ridx=4
            if (ridx+1>=sequnces.size()) break;
            ridx++;
            //arr[5] ridx=4;
            sum+=sequnces[ridx];
            // dfs(sum+sequnces[idx+1], idx+1, lidx, ridx);
            // dfs(sum, idx+1,lidx, ridx);
        }
    }
    
    sort(arrs.begin(),arrs.end(),compare);
    answer.push_back(arrs[0].first);
    answer.push_back(arrs[0].second);
    return answer;
}

int main()
{
    auto p=solution({1, 2, 3, 4, 5}, 7);
    
    for (auto k:p)
    {
        cout<<k<<endl;
    }
}