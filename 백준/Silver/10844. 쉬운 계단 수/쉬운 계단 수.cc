#include <iostream>
#include <vector>

using namespace std;

int main(){

     int n;
     int MOD=1000000000;
    cin>>n;
     vector<vector<long long>> dp(n+1,vector<long long>(10,0));


     for (int i=1;i<=9;i++) {
         dp[1][i]=1;
     }//i자리 수, j로 끝나는 수로 체킹

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j<9)dp[i][j]+=dp[i-1][j+1]%MOD;
            if(j>0)dp[i][j]+=dp[i-1][j-1]%MOD;
            //j=0일땐 +1만 챙기고, j=9일땐 -1 8만챙기기
            //0~9까지 챙기되, j=0일때 9,1 j=9일때 0,8 j=5일때 4,6
        }
    }
    int result = 0;
    for (int j = 0; j <= 9; j++) {
        result = (result + dp[n][j]) % MOD;
       
    }
    cout<<result<<endl;

}