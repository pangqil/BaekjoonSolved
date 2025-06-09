#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;

    cin>>n;

    vector<int> p(n+1, 0);
    vector<int> dp(n+1,0);


    for (int i=1;i<=n;i++) {
        cin>>p[i];
    }


    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            dp[i]=min(dp[i],dp[i-j]+p[j]);
            if (dp[i]==0) {
                dp[i]=dp[i-j]+p[j];
            }
        }
    }
    cout<<dp[n];
}//i=4 j=1 -> dp[4]=min(dp[4],dp[3]+p[1],dp[2]+p[2]+dp[1]+dp[3]