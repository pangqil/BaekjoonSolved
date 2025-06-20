#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> dp(n);
    for (int i=0;i<n;i++) {
        cin>>A[i];
    }
    dp[0]=A[0];
    int maxsum=A[0];
    for (int i=1;i<n;i++) {
        dp[i]=max(A[i],dp[i-1]+A[i]);
        maxsum=max(maxsum,dp[i]);
    }
    cout<<maxsum;
}