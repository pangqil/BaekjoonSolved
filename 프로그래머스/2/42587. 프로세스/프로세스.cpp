#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer=0;
    
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
    }
    sort(priorities.begin(),priorities.end(), greater<int>());
    
    int prioridx=0;
    while(!q.empty()){
        int q_prior=q.front().first;
        int q_idx=q.front().second;
        q.pop();
        if(priorities[prioridx]==q_prior){
            answer++;
            prioridx++;
            if(location==q_idx) return answer;
        }
        else{
            q.push({q_prior,q_idx});
        }
    }
    
    return answer;
}

//[2,1,3,2] -> [3 2 2 1]
//(2,0) (1,1) (3,2) (2,3)