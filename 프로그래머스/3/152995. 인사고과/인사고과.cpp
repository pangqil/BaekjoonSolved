#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(vector<int> a,vector<int> b)
{
    if(a[0]!=b[0])
        return a[0]>b[0];
    
    return a[1]<b[1];
}

int solution(vector<vector<int>> scores)
{
    int wanhoA=scores[0][0];
    int wanhoB=scores[0][1];
    int wanhoSum=wanhoA+wanhoB;

    sort(scores.begin(),scores.end(),compare);

    int maxPeer=0;
    int rank=1;

    for(auto score:scores)
    {
        int a=score[0];
        int b=score[1];

        if(b<maxPeer)
        {
            if(a==wanhoA&&b==wanhoB)
            {
                return -1;
            }
            continue;
        }

        maxPeer=max(maxPeer,b);

        if(a+b>wanhoSum)
        {
            rank++;
        }
    }

    return rank;
}