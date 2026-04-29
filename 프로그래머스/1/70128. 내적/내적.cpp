#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int vecs=a.size();
    int ans=0;
    for(int i=0;i<vecs;i++){
        ans+=a[i]*b[i];
    }
    return ans;
}