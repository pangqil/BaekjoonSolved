#include <iostream>
#include <vector>

#define MOD 9901
#define INF 1000000;
using namespace std;

int main() {
    int n;
    int result=INF;
    cin>>n;
    vector <vector<int>> dp(n+1, vector<int>(3,0));
    vector <vector<int>> cost(n+1, vector<int>(3,0));

    for(int i=0;i<n;i++) {
        for (int j=0;j<3;j++) {
            cin>>cost[i][j];
        }
    }

    for (int first=0;first<3;first++) {//rgb순서대로 돌릴게.
        for (int k=0;k<3;k++) {//r고정시키고 나머지 INF로.
            if (k==first) {
                dp[0][first]=cost[0][first];
            }
            else dp[0][k]=INF;
        }
        for (int i=1;i<n;i++) {
                dp[i][0]=min(dp[i-1][1], dp[i-1][2])+cost[i][0];
                dp[i][1]=min(dp[i-1][0],dp[i-1][2])+cost[i][1];
                dp[i][2]=min(dp[i-1][0], dp[i-1][1])+cost[i][2];
        }
        for (int j=0;j<=2;j++) {
            if (j==first) continue;
            result=min(result, dp[n-1][j]);
        }

    }


    cout<<result;
        //ox 0
        //xo xx

        //xo 1
        //ox xx

        //xx 2
        //ox xo xx

}
