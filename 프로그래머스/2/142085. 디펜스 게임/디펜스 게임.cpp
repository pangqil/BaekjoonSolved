#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

//k가 무적권

bool compare(int a, int b)
{
    return a>b;
}

int solution(int n, int k, vector<int> enemy) {
    int answer=0;
    priority_queue<int> pq;
    
    for (int round=0;round<enemy.size();round++)
    {
        pq.push(enemy[round]);
        n-=enemy[round];
        if (n<0)
        {
            if (k>0&&!pq.empty())
            {
                k--;
                n+=pq.top();
                pq.pop();
            }
            else
            {
                return answer;
            }
        }
        
        answer++;
    }
    return answer;
}