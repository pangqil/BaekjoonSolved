#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/ranges_algo.h>

using namespace std;

int main() {
    vector<int> v(9);
    int sum=0;
    int a;
    int b;
    for (int i = 0; i <9; i++) {
        cin>>v[i];
        sum+=v[i];
    }
    sort(v.begin(),v.end());
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (sum-v[i]-v[j]==100) {
                a=i;
                b=j;
            }
        }
    }

    for (int k:v) {
        if (k!=v[a]&&k!=v[b]) {cout<<k<<endl;}

    }
}