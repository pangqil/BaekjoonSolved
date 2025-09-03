#include <iostream>
#include <vector>

#define MOD 9901

using namespace std;

int main() {
    int n,m;
    cin>>n;
    vector <vector<int>> dp(n+1, vector<int>(3,1));

    for(int i=0;i<=2;i++) {
        cin>>dp[0][i];
    }

    for (int i=1;i<n;i++) {
        for (int j=0;j<3;j++) {
            cin>>dp[i][j];
        }
        dp[i][0]=min(dp[i][0]+dp[i-1][1], dp[i][0]+dp[i-1][2]);
        dp[i][1]=min(dp[i][1]+dp[i-1][0],dp[i][1]+dp[i-1][2]);
        dp[i][2]=min(dp[i][2]+dp[i-1][0], dp[i][2]+dp[i-1][1]);

    }
    n--;
    int result=min(dp[n][0],dp[n][1]);
    result=min(result,dp[n][2]);
    cout<<result;
    //ox 0
    //xo xx

    //xo 1
    //ox xx

    //xx 2
    //ox xo xx
}
