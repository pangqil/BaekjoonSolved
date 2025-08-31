#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int LIS=0;
    vector<int> v;
    vector<int> dp;

    cin>> n;
//1,2,1,3,1,4,2  4  dp[5]=dp[3]+1;//dp[4]는 패스해야됨. dp[4]는 1인데, 그럼 dp
    //dp[0]=dp[j]+1
    v.resize(n+1,1);
    dp.resize(n+1,1);
    for(int i=0;i<n;i++) {
        cin>>v[i];

    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (v[j]<v[i]) {
                dp[i]=max(dp[i],dp[j]+1);//main code
            }
        }
        LIS=max(LIS,dp[i]);
    }
    cout<<LIS;
}