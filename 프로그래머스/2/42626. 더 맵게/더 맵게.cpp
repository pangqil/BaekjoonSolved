#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int mergesc=0;
int mcount=0;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto s: scoville)
    {
        pq.push(s);
    }
    
    while (pq.size()>=2)
    {
        
        if (pq.top()>=K) return mcount;
        
       
        int fidx=pq.top();
        pq.pop();
        int sidx=pq.top();
        pq.pop();
        
        int nidx=fidx+sidx*2;
        
        pq.push(nidx);
        
        mcount++;
    }
    if (pq.size()==1)
    {
        if (pq.top()>=K) return mcount;
    }
    return -1;
}

int main()
{
    std::cout<<solution({1,2,3,9,10,12}, 7);
}