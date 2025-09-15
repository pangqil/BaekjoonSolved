#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> mt;
vector<vector<bool>> visit;
vector<vector<int>> check;
int m,n;
int cyclesx=-1;
int cyclesy=-1;
int cycleex=-1;
int cycleey=-1;
int dontpos=-1;
bool cyclecheck=false;

void dfs(int x, int y, int px, int py);

int main(){
    cin>>n>>m;
    mt.resize(n,vector<char>(m));
    visit.resize(n,vector<bool>(m, false));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>mt[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (cyclecheck) return 0;
            if (visit[i][j]==1) {continue;}
            dfs(i,j,-1,-1);
        }
    }
    cout<<"No";
    return 0;
}

void dfs(int x, int y, int px, int py) {
    int dx[4]={0,0,-1,1};//상,하,좌,우
    int dy[4]={1,-1,0,0};
    visit[x][y]=true;
    for (int k=0;k<4;k++) {//상 = 0
        int newx=x+dx[k];
        int newy=y+dy[k];

        if (newx==px&&newy==py) {continue;}

        if (newx<0 || newx>=n || newy<0 || newy>=m) {continue;}


        if (mt[newx][newy]==mt[x][y]) {//
            if (visit[newx][newy]==1) {
                cyclecheck=true;
                cout<<"Yes";
                return;
            }
            dfs(newx,newy,x,y);
            if (cyclecheck) {
                return;
            }
        }


    }
    return;
}