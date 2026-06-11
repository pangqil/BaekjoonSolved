#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct planinfo
{
    string name;
    int start;
    int play;
};

bool compare(planinfo a, planinfo b)
{
    return a.start<b.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<planinfo> plan_list;
    
    for (int i=0;i<plans.size();i++)
    {
        string name=plans[i][0];
        string start=plans[i][1];
        int play=stoi(plans[i][2]);
        
        stringstream ss(start);
        int hour;
        char sign;
        int min;
        ss>>hour>>sign>>min;
        int starttime=hour*60+min;
        plan_list.push_back({name,starttime,play});
    }
    
    sort(plan_list.begin(),plan_list.end(),compare);
    
    stack<planinfo> s;
    int curtime=0;
   
    for (auto cur:plan_list)
    {
        if (s.empty())
        {
            curtime=cur.start;
        }
        while (!s.empty()&&curtime<cur.start)
        {
            int gap=cur.start-curtime;
            if (s.top().play<=gap)
            {
                curtime+=s.top().play;
                answer.push_back(s.top().name);
                s.pop();
            }
            else
            {
                s.top().play-=gap;
                curtime=cur.start;
                break;
            }
        }
        curtime=cur.start;
        s.push(cur);
    }

    while (!s.empty())
    {
        answer.push_back(s.top().name);
        s.pop();
    }
    return answer;
}
