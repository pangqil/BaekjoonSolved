#include <iostream>
#include <vector>

#define MOD 1000000000
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k,n;

    cin>>n>>k;
    vector<vector<long long>> dp(k+1, vector<long long>(n+1, 0));

    for (int i=1;i<=k;i++) {
        dp[i][0]=1;
    }
    for (int i=0;i<=n;i++) {
        dp[1][i]=1;
    }

    //dp[i][k]=sn dp[2][0]~dp[2][20]
    for (int i=2;i<=k;i++) {//숫자의 갯수
        for (int j=1;j<=n;j++) {//dp[i][j]는 한층 아래의 합.
            for (int f=0;f<=j;f++) {
                dp[i][j]=(dp[i][j]+dp[i-1][j-f])%MOD;
            }//dp[3][1]+=dp[2][6-0)
        }//j=1 dp[2][1]=sn(dp[1][1~20]
    }
//3개밖에 없는데... [3][1]=[2][0]+[2][1]인데 이건
    cout<<dp[k][n];


}

//dp[3][20]=dp[2][20-20]
//dp[3][n]= 앞이 0일땐 dp[2][n]
//dp[3][n-1] = 앞이 1일떈 뒤에 1뺴고
//dp[3][n-20] = 앞이 20일떈 뒤에 20빼고.
//dp[3][20]은 n+1에다가 sn -> dp[2][0]~dp[2][20] 까지 더 한 경우의 수

