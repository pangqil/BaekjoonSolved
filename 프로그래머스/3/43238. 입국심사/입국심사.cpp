#include <iostream>
#include <string>
#include <vector>

using namespace std;
//8:30
//기다리는 사람 n명
//각 심사관이 붙잡는거 times
//모든 사람의 심사가 끝나는 경우
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long minvalue=times[0];
    
    for (int i = 0; i < times.size(); i++)
    {
        minvalue=min(minvalue, (long long)times[i]);
    }
    
    long long left=1;
    long long right=minvalue*n;
    
    
    
    
    while (left<=right)
    {   
        long long mid=left+(right-left)/2;
        
        long long sum=0;
        
        for (int i=0;i<times.size();i++)
        {
            sum+=mid/times[i];
        }
        if (n>sum)//n이 6인데 sum이 5 ex) mid가 27
        {
            //시간을 더주기 -> mid를 오른쪽으로 옮기기
            left=mid+1;
        }
        else if (n<=sum)//n이 6인데 sum이 7  ex) mid가 30 
        {
            //시간을 더 빼기 -> mid를 왼쪽으로 옮기기
            answer=mid;
            right=mid-1;
        }

    }

    return answer;
}

int main()
{
    cout<<solution(6,{7,10});
}

//6
//7,10 
//7 14 21....
//10 20 30....