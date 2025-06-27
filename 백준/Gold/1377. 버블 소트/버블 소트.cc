#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int k;
    cin>>N;
    vector<pair<int, int>> v(N+1);
    for (int i = 1; i <= N; i++) {
        cin>>v[i].first;//첫번째 인덱스에 value(value대로 정렬됨)
        v[i].second = i;//두번째 인덱스에 정렬전 index
    }//i는 정렬전 인덱스. 이를 second에 넣고, first엔 value
    sort(v.begin(), v.end());
    int maxn=0;
    for (int i = 1; i <= N; i++) {
        maxn=max(maxn,v[i].second-i);
    }
    cout<<maxn+1;



}