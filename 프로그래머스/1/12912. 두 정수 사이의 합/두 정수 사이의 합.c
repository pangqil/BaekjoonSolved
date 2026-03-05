#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    if(b<a){
        long long temp=0;
        temp=a;
        a=b;
        b=temp;
    }
    for(long long i=a;i<=b;i++){
        answer+=i;
    }
    return answer;
}