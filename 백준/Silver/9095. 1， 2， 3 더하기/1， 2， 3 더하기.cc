#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int k;
    std::vector<int> vc(11);


    vc[0]=0;
    vc[1]=1;
    vc[2]=2;
    vc[3]=4;
    cin>>n;
    std::vector<int> re;

    for (int i=4;i<12;i++) {
        vc[i]=vc[i-1]+vc[i-2]+vc[i-3];
    }
    for (int i=0;i<n;i++) {
        cin>>k;
        re.push_back(k);
    }
    for (int t:re) {
        cout<<vc[t]<<endl;
    }

}