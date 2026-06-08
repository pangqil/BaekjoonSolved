#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int cur=1;
    
    stack<int> assist;
    vector<int> truck;
    
    for (int i=0;i<order.size();i++)
    {
        while (assist.empty()||assist.top()!=order[i]&&cur<=order.size())
        {
            assist.push(cur++);
        }
        if (assist.empty()) break;
        
        int output=assist.top();
        assist.pop();
    
        if (output!=order[i]) 
            break;
        truck.push_back(output);
    }
    answer=truck.size();
    return answer;
}
