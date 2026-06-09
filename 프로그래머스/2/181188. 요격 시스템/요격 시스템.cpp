#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    int lastshot=-1;
    
    sort(targets.begin(),targets.end(),compare);
    for (auto target:targets)
    {
        int start=target[0];
        int end=target[1];
        
        if (lastshot<=start)
        {
            answer++;
            lastshot=end;
        }
    }
    
    return answer;
}
