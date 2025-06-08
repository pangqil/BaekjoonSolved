#include <iostream>
#include <vector>

using namespace std;

//p[n]=k 일때 n이 가장 작은것 우선, k는 가격일때, n개를 갖기 위한 금액의 최대값을 구하시오.
int main() {
    int n,k;
    cin>>n;
    vector<int> p(n+1, 0);
    vector<int> dp(n+1,0);

    for (int i=1;i<=n;i++) {
        cin>>p[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            dp[i]=max(dp[i],dp[i-j]+p[j]);
        }

    }
    cout<<dp[n];

}