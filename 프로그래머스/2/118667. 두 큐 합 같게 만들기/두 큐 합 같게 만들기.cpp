#include <deque>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    deque<int> dq1(queue1.begin(), queue1.end());
    deque<int> dq2(queue2.begin(), queue2.end());
    int answer = -2;
    long long sum1=0, sum2=0, total=0;
    for (int cur1:queue1)sum1+=cur1;
    for (int cur2:queue2)sum2+=cur2;
    total=sum1+sum2;
    long long target=total/2;
    if (total%2!=0) return -1;
    
    int limit=dq1.size()*4;
    int count=0;
    while (count<limit)
    {
        if (sum1 == target) return count;
        if (sum1 > target) 
        {
            if (dq1.empty()) break;
            int val = dq1.front();
            dq1.pop_front();
            dq2.push_back(val);
            sum1 -= val;
            sum2 += val;
        }
        else {
            if (dq2.empty()) break;
            int val = dq2.front();
            dq2.pop_front();
            dq1.push_back(val);
            sum2 -= val;
            sum1 += val;
        }
        count++;
    }
    return -1;
}