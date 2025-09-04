#include <iostream>
#include <vector>

using namespace std;

bool flag=false;
void dfs(int cur, vector<vector<int>> &edge, vector<int> &color);

int main() {
    int n,vs,es;
    int a,b;
    cin>>n;

    for (int tcase=0;tcase<n;tcase++) {//test case
        cin>>vs>>es;
        vector<vector<int>> edge(vs+1);
        vector<int> color(vs+1,-1);
        flag=false;
        for (int i=0;i<es;i++) {
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for (int i = 1; i <= vs; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                dfs(i, edge, color);
            }
            if (flag) {
                break;
            }
        }
        flag?cout<<"NO\n":cout<<"YES\n";
    }
}

void dfs(int cur, vector<vector<int>> &edge, vector<int> &color) {
    for (int next:edge[cur]) {
        if (color[next]!=-1) {//is visit
            if (color[next]==color[cur]) {
                flag=true;
                return;
            }
        }
        else {//isn't visit
            if (color[cur]==1)color[next]=0;
            else color[next]=1;
            dfs(next,edge,color);
            if (flag) return;
        }
    }

}



