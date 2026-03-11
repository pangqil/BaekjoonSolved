#include <iostream>

using namespace std;
//트리의 부모 -> 짝수 노드 -> (n+1)/2

int solution(int n, int a, int b)
{
    int answer = 0;

    while(a!=b){
        a=(a+1)/2;
        b=(b+1)/2;
        answer++;
    }
    
    return answer;
}