#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define MAX_SIZE 10000000


bool compare(pair<int,int> &a, pair<int,int> &b){
    return a.second>b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer=0;
    map<int,int> tcount;
    
    for(int idx:tangerine){
        tcount[idx]++;
    }
    vector<pair<int,int>> larger(tcount.begin(), tcount.end());
    sort(larger.begin(), larger.end(), compare);
    
    int idx=0;
    
    while(k>0){
        k-=larger[idx].second;
        answer++;
        idx++;
    }
    
    return answer;
}