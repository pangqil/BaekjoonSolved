#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000009; //

int main() {
    int n,k;
    cin>>n;

    vector<int> v(n);
    int max_k=0;

    for(int i=0;i<n;i++) {
        cin>>v[i];
        max_k=max(max_k,v[i]);
    }
    vector<vector<long long>> dp(max_k+1, vector<long long>(4, 0));

    dp[1][1]=1;
    dp[2][2]=1;
    dp[3][1]=1;//2 1
    dp[3][2]=1;//1 2
    dp[3][3]=1;//3

    for (int i=4;i<=max_k;i++) {
        dp[i][1]=(dp[i-1][2]+dp[i-1][3])%MOD;
        dp[i][2]=(dp[i-2][1]+dp[i-2][3])%MOD;
        dp[i][3]=(dp[i-3][2]+dp[i-3][1])%MOD;
    }


    for (int x:v) cout<<(dp[x][1]+dp[x][2]+dp[x][3])%MOD<<endl;
}