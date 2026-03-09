#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n<=1) return n;
    
    int first=0;
    int second=1;
    
    for(int i=2;i<=n;i++){
        int next=(first+second)%1234567;
        first=second;
        second=next;
    }
    return second;
}

