#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long f1=1, f2=2, current=0;
    for(int i=3;i<=n;i++){
        current=(f1+f2)%1234567;
        f1=f2;
        f2=current;
    }
    
    if(n==1) return 1;
    if(n==2) return 2;
    return f2;
}