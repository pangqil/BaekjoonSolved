#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    unordered_set<int> cake1;
    unordered_map<int, int> cake2;//케이크 번호, 갯수
    int answer=0;
    for (int i=0;i<topping.size();i++)
    {
        cake2[topping[i]]++;
    }
 
    int idx=0;
    
    while (idx<topping.size())
    {
        cake1.insert(topping[idx]);
        cake2[topping[idx]]--;
        if (cake2[topping[idx]]==0) cake2.erase(topping[idx]);
        if (cake1.size()==cake2.size()) answer++;
        idx++;
    }
    
    return answer;
}