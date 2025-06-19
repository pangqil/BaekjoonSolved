#include <iostream>
#include <vector>

using namespace std;
//0으로 시작하지 않음. 이친수에서는 1이 두번 연속으로 나타나지 않음.
int main() {
    int n;
    cin>>n;
    vector<vector<long long>> dp(n+1,(vector<long long>(2,0)));
    dp[1][0]=0;
    dp[1][1]=1;
    //n자리 수일때, n-1자리수로 해야하며 11을 부분 문자열로 X
    for(int i=2;i<=n;i++) {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[n][0]+dp[n][1]<<endl;
}
//중요한건 앞자리가 1이냐 0이냐의 차이
//앞자리가 1이면 0이어야 하지만, 0으로 끝나면 아무거나 가능.
//앞자리
//