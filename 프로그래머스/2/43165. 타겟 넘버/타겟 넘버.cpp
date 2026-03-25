#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<bool> visit;
int answer = 0;

void dfs(vector<int>& numbers, int target, int stindex, int sumcount, int stackcount);
int solution(vector<int> numbers, int target) {
  
    visit.resize(numbers.size(), false);
    dfs(numbers, target, 0, 0, 0);
    return answer;
}

void dfs(vector<int>& numbers, int target, int stindex, int sumcount, int stackcount){
    if (stackcount==numbers.size())
    {
        if (sumcount==target)
        {
            answer++;
        }
        return;
    }
    for (int i=stindex;i<numbers.size();i++)
    {
        if (visit[i]==false)
        {
            visit[i]=true;
            dfs(numbers, target, i+1, sumcount+numbers[i], stackcount+1);
            dfs(numbers, target, i+1, sumcount-numbers[i], stackcount+1);
            visit[i]=false;
            return;
        }
    }
}