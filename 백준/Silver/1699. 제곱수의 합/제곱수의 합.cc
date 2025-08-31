#include <iostream>
#include <math.h>
#include <valarray>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> dp(100001,4);

    int k=sqrt(n);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=sqrt(i);j++) {
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }//dp[3-4]+1
    }
    cout<<dp[n];
}

