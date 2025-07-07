#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<long long> Eprim;
    long long a,n;
    long long count=0;

    cin>>a;
    cin>>n;
    long long limit=sqrt(n);
    Eprim.resize(limit+1);

    for(long long i=2;i<=limit;i++) {
        Eprim[i]=i;
    }
    Eprim[1]=0;
    for (long long i=2; i*i<=limit;i++) {
        for (long long j=i*i;j<=limit;j+=i) {
            if (Eprim[j]==0) continue;
            Eprim[j]=0;
        }
    }
    //Eprim이 0이 아니어야 소수다.
    long long pown;
    for (long long i=2;i<=sqrt(n);i++) {
        if (Eprim[i]!=0) {
            pown=i*i;
            while (pown<=n) {
                if (pown>=a) count++;
                if (pown>(n/i)) break;
                pown*=i;
            }
        }

        }

    cout<<count<<endl;


}
