#include <map>
#include <string>
#include <vector>

using namespace std;

#define Day 10

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer=0;
    map<string, int> DList;
    map<string, int> CheckList;
    
    for (int i=0;i<want.size();i++)
    {
        DList[want[i]]=number[i];
    }
    

    for (int i=0;i<Day;i++)
    {
        CheckList[discount[i]]++;
    }
    
    int sidx=0;
    int lidx=9;
    
    for (int i=0;i<=discount.size()-Day;i++)
    {
       if (DList==CheckList)
       {
           answer++;
       }
        if (i<discount.size()-Day)
        {
            CheckList[discount[i]]--;
            if (CheckList[discount[i]]==0)
            {
                CheckList.erase(discount[i]);
            }
            CheckList[discount[i+Day]]++;
        }
    }
    
    return answer;
}