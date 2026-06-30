#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job{
    int number;
    int request;
    int duration;
};

struct Compare{
    bool operator()(const Job& a,const Job& b){
        if(a.duration!=b.duration)return a.duration>b.duration;
        if(a.request!=b.request)return a.request>b.request;
        return a.number>b.number;
    }
};

int solution(vector<vector<int>> jobs){
    vector<Job> jobList;

    for(int i=0;i<jobs.size();i++){
        jobList.push_back({i,jobs[i][0],jobs[i][1]});
    }

    sort(jobList.begin(),jobList.end(),[](const Job& a,const Job& b){
        if(a.request!=b.request)return a.request<b.request;
        return a.number<b.number;
    });

    priority_queue<Job,vector<Job>,Compare> waiting;

    long long totalTime=0;
    int currentTime=0;
    int index=0;
    int completed=0;

    while(completed<jobList.size()){
        while(index<jobList.size()&&jobList[index].request<=currentTime){
            waiting.push(jobList[index]);
            index++;
        }
        
        if(waiting.empty()){
            currentTime=jobList[index].request;
            continue;
        }

        Job current=waiting.top();
        waiting.pop();

        currentTime+=current.duration;
        totalTime+=currentTime-current.request;
        completed++;
    }

    return totalTime/jobs.size();
}