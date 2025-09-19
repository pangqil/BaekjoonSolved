#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 1001

struct Emo {
    int display;
    int clip;
    int time;
};

vector<vector<int>> visit;
vector<Emo> dp;
int s;


int bfs(Emo st);

int main() {

    cin>>s;
    visit.resize(MAX, vector<int>(MAX, 0));

    cout<<bfs({1,0,0});

}

int bfs(Emo st) {
    visit[1][0]=1;
    queue<Emo> q;
    q.push({1,0,0});

    while (!q.empty()) {
        int display=q.front().display;
        int clip=q.front().clip;
        int time=q.front().time;

        q.pop();

        if (display==s) {
            return time;
        }

        if (display>0&&display<=1000) {
            if (visit[display][display]==0) {//복사
                visit[display][display]=1;//만약 복사가 미리 되어있으면, time+1안해도 됨.
                q.push({display,display,time+1});
            }
            if (visit[display+clip][clip]==0&&clip>=1&&display+clip<MAX) {//붙여넣기
                visit[display+clip][clip]=1;
                q.push({display+clip,clip,time+1});
            }
            if (visit[display-1][clip]==0&&display-1>0) {//삭제
                visit[display-1][clip]=1;
                q.push({display-1,clip,time+1});
            }
        }

    }
//6
    //
}

