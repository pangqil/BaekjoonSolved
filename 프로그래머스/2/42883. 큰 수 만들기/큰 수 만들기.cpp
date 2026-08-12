#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ncount[10]={0};
//1924 -> 94 k->2
string solution(string number, int k) {
    
    string answer = "";
    int nlen=number.length()-k;
    
    for (char cur:number)
    {
        while (!answer.empty())
        {
            if (k<=0) break;
            if (answer.back()>=cur) break;
            answer.pop_back();
            k--;
        }
        answer.push_back(cur);
    }
    
    if (k>0)
    {
        answer.resize(answer.length() - k);
    }
    
    return answer;
}

int main()
{
    cout<<solution("4177252841", 4);
}