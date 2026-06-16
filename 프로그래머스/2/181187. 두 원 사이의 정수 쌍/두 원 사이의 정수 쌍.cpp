#include <string>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;long long solution(int r1, int r2) {
    long long answer = 0;
    
    for (int i=1;i<=r2;i++)
    {//r^2=x^2+y^2 -> y=sqrt(r^2-x^2)
        int minY=ceil(sqrt((long long)r1*r1-(long long)i*i));
        int maxY=floor(sqrt((long long)r2*r2-(long long)i*i));
        
        if (i>r1) minY=0;
        answer+=(maxY-minY+1);    
    }
    
    return answer*4;
}