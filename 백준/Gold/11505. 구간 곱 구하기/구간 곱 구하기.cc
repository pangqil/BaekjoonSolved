#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
vector<long long> v;
vector<long long> tree;
int st;
int n,m;


void maketree() {
    for (int i=1;i<=n;i++) {
        tree[i+st-1]=v[i]%MOD;
    }

    for (int i=st-1;i>0;i--) {
        tree[i]=(tree[2*i]*tree[2*i+1])%MOD;
    }
}

long long mtree(int l, int r) {
    long long res=1;
    l+=st-1;
    r+=st-1;
    while (l<r) {//9 12 -> 10 12 -> 5/6 l++ tree[5]*tree[9]
        if (l%2==1) {
            res=res*tree[l]%MOD;
            l++;
        }
        if (r%2==0) {
            res=res*tree[r]%MOD;
            r--;
        }
        l/=2;
        r/=2;
    }
    if (l==r) {
        res=res*tree[l]%MOD;
    }
    return res;
}

void updatetree(int b, int c) {
    int upidx=st+b-1;
    tree[upidx]=c%MOD;//8+3-1=10 tree[10]=c
    while (upidx>1) {
        upidx/=2;
        tree[upidx]=(tree[2*upidx]*tree[2*upidx+1])%MOD;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x;
    int k;
    cin>>n>>m>>k;
    v.resize(n+1);
    for (int i=1;i<=n;i++) {
        cin>>x;
        v[i]=x;
    }

    int treeheight=ceil(log2(n));
    st=1<<(treeheight);
    tree.resize(2*st,1);
    maketree();
    int a,b,c;
    for (int i=0;i<m+k;i++) {
        cin>>a>>b>>c;
        if (a==1) {
            updatetree(b,c);
        }
        else if (a==2) {
            cout<<mtree(b,c)<<"\n";
        }
    }
}
