#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> v;
int func(int n);
int solution(int number, int limit, int power) {
    int answer = 0;

    
    for (int i=1;i<=number;i++)
    {
        int silver=func(i);
        if (silver>limit)
        {
            silver=power;
        }
        v.push_back(silver);
    }
    
    for (auto p:v)
    {
        answer+=p;
    }
    return answer;
}

int func(int n)
{
    int temp=0;
    for (int i=1;i<=n;i++)
    {
        if (n%i==0)
            temp++;
    }
    return temp;
}
