#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int curi=0;
    int time=1;
    int cur_weight=0;
    deque<pair<int,int>> bridge_q;
    while (curi<truck_weights.size()||!bridge_q.empty())
    {
        time++;
        if (curi!=truck_weights.size())
        {
            if (truck_weights[curi]+cur_weight<=weight)
            {
                bridge_q.push_back({truck_weights[curi],0});
                cur_weight+=truck_weights[curi++];
            }
        }
       
        for(auto& idx:bridge_q)
        {
            idx.second++;
        }
        if (bridge_q.front().second==bridge_length)
        {
            cur_weight-=bridge_q.front().first;
            bridge_q.pop_front(); 
            
        }
    }
    return time;
}

int main()
{
    cout<<solution(2,10,{7,4,5,6});
}