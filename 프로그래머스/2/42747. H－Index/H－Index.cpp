#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<int> citations) {
    int answer=0;
    //h번이상 인용된 논문 h 편이상 -> i+1
    //현재 논문 인용횟수 -> citations[i]
    sort(citations.begin(),citations.end(),greater<int>());
    for (int i=0;i<citations.size();i++)
    {
        if (citations[i]>=i+1)
        {
            answer=i+1;
        }
    }
    
    //6,5,3,1,0 - citations[i]
    //1,2,3,4,5 - i+1
    //
    return answer;
}