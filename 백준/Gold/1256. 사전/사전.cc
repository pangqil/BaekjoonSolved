#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000

int fac(int n) {
    if (n==1||n==0) return 1;
    else return n*fac(n-1);
}
int com(int n, int k) {
    //n!/(n-k)!k!
    return (fac(n)/(fac(n-k)*fac(k)));
}

int main() {
    int n,m,k;
    int ac=0, zc=0;
    vector<vector<int>> dp(101, vector<int>(101 ,0));
    string sv={};
    cin>>n>>m>>k;
    dp[0][0]=0;
    for (int i=1;i<101;i++) {
        dp[0][i]=1;
        dp[i][0]=1;
    }

    for (int i=1;i<101;i++) {
        for (int j=1;j<101;j++) {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            if (dp[i][j]>1e9) dp[i][j]=1e9;
        }
    }//n,m,k
    if (k>dp[n][m]) {
        cout<<"-1";
        return 0;
    }
    int count=n+m;
    while (count>0) {
        if (n==0){sv.push_back('z');m--;}
        else if (m==0){sv.push_back('a');n--;}
        else if (dp[n-1][m]>=k) {//a가 먼저오는 케이스가 k보다 많으면
            n--;
            sv.push_back('a');
        }
        else{//a가 먼저오는 케이스가 k보다 많으면
            k-=dp[n-1][m];
            m--;
            sv.push_back('z');
        }
        count--;
    }
    
    cout<<sv;
}