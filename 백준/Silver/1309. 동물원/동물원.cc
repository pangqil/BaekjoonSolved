#include <iostream>
#include <vector>

#define MOD 9901

using namespace std;

int main() {
    int n,m;;
    cin>>n;
    vector <vector<int>> dp(n+1, vector<int>(3,1));

    for (int i=1;i<n;i++) {
        dp[i][0]=(dp[i-1][1]+dp[i-1][2])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
    }

    n--;
    int result=dp[n][0]+dp[n][1]+dp[n][2];
    result%=MOD;
    cout<<result;
    //ox, xo, xx

    //ox 0
    //xo xx

    //xo 1
    //ox xx

    //xx 2
    //ox xo xx
}
