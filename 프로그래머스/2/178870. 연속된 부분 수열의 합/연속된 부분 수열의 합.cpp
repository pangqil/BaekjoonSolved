#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    int alen=a.second-a.first;
    int blen=b.second-b.first;
    //길이가 짧은건 앞으로 가고, 같다면 시작인덱스가 작은것
    if (alen!=blen)
    {
        return alen<blen;
    }
    else
    {
        return a.first<b.first;
    }
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int,int>> seq;
    int lidx=0;
    int ridx=0;
    int count=0;
    int sum=sequence[0];
    int curlen=0;
    int minlen=0;
    
    while(lidx<sequence.size()&&ridx<sequence.size())
    {
        if (sum==k)
        {
            seq.push_back({lidx,ridx});
            sum-=sequence[lidx];
            lidx++;
        }
        else if (sum>k)
        {
            sum-=sequence[lidx];
            if (lidx==sequence.size()) break;
            lidx++;
        }
        else if (sum<k)
        {
            ridx++;
            if (ridx==sequence.size()) break;
            sum+=sequence[ridx];
        }
    }
    
    sort(seq.begin(),seq.end(),compare);
    
    
    answer.push_back(seq[0].first);
    answer.push_back(seq[0].second);
    return answer;
}

int main()
{
    solution({1, 1, 1, 2, 3, 4, 5}, 5);
}