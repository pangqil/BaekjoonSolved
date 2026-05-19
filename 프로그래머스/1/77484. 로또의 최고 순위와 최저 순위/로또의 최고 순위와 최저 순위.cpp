#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count=0;
    int upcount=0;
    for (int num: lottos)
    {
        if (num==0) upcount++;
        if (find(win_nums.begin(),win_nums.end(),num)!=win_nums.end())
        {
            count++;
        }
    }
    int high=7-count-upcount;
    if (high==7) high=6;
    int low=7-count;
    if (low==7) low=6;
    
    
    return {high,low};
}
