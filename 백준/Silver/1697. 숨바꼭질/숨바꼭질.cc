#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 100001
vector<int> dp;
vector<bool> visit;

void bfs(int start,int a, int b);

int main() {
    int a,b;
    cin>>a>>b;
    visit.resize(INF*2,false);
    bfs(a,a,b);
}

void bfs(int start,int a, int b) {
    queue<pair<int,int>> q;
    q.push({start,0});

    while (!q.empty()) {
        int x=q.front().first;
        int count=q.front().second;
        q.pop();
        if (x==b) {
            cout<<count;
            return;
        }
        if (x+1<=b*2) {
            if (!visit[x+1]) {
                visit[x+1]=1;
                q.push({x+1,count+1});
            }
        }
        if (x-1>=0) {
            if (!visit[x-1]) {
                visit[x-1]=1;
                q.push({x-1,count+1});
            }
        }
        if (x*2<=b*2) {
            if (!visit[x*2]) {
                visit[x*2]=1;
                q.push({x*2,count+1});
            }
        }
    }
}