#include <iostream>
#include <vector>

using namespace std;

long long fac(long long k) {
    if (k==0||k==1) {
        return 1;
    }
    else {
        return k*fac(k-1);
    }
}


int main() {
    int n;
    int N,M;

    cin>>n;

    for (int i=0;i<n;i++) {
        cin>>N>>M;
        long answer=1;
        int k=1;
        for (int j=M;j>M-N;j--) {
            answer*=j;
            answer/=k;
            k++;
        }
        cout<<answer<<"\n";
    }
}