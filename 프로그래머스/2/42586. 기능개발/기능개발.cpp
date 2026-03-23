#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for (int i=0;i<progresses.size();i++)
    {
            int restp=100-progresses[i];
            int needsday=ceil(float(restp)/speeds[i]);
            days.push_back(needsday);
    }

    int maxday=days[0];
    int count=1;
    //3 1 2 5 7 
    for (int i=1;i<days.size();i++)
    {
        if (days[i]<=maxday)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            maxday=days[i];   
            count=1;
            
        }
    }
    answer.push_back(count);
    
    return answer;
}