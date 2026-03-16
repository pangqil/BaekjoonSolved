#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int n=elements.size();
    set<int> sums;
    
    for(int i=0;i<n;i++){
        int thissum=0;
        for(int len=0;len<n;len++){
            thissum+=elements[(i+len)%n];
            sums.insert(thissum);
        }
    }
    return sums.size();
}