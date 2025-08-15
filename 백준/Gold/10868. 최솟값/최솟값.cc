#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> tree;
int st;
int n,m;


void maketree() {
    for (int i=1;i<=n;i++) {
        tree[i+st-1]=v[i];
    }
    for (int i=st-1;i>0;i--) {
        tree[i]=min(tree[2*i],tree[2*i+1]);
    }
}
int mintree(int l,int r) {
    l+=st-1;
    r+=st-1;
    int minn=1000000000;
    while (l<=r) {
        if (l%2==1) {
            minn=min(minn,tree[l++]);
        }
        if (r%2==0) {
            minn=min(minn,tree[r--]);
        }
        l/=2;
        r/=2;
    }
    return minn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,x;
    cin>>n>>m;
    v.resize(n+1);
    for (int i=1;i<=n;i++) {
        cin>>x;
        v[i]=x;
    }

    int treeheight=ceil(log2(n));
    st=1<<(treeheight);
    tree.resize(2*st,1000000000);
    // tree.assign(2 * st, 1000000000);
    maketree();

    for (int k=0;k<m;k++) {
        cin>>a>>b;
        cout<<mintree(a,b)<<"\n";
    }
}