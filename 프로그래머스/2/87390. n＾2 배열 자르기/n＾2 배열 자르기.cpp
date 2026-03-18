#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    vector<int> ans;
    answer.reserve(right-left+1);
    
    for (long long i = left; i <= right; i++)
    {
        long long row=i/n;
        long long col=i%n;
        answer.push_back(max(row+1,col+1));
    }
    
    return answer;
}
