#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Group
{
    int diamond=0;
    int iron=0;
    int stone=0;
    int weight=0;
};


bool compare(Group a, Group b)
{
    return a.weight>b.weight;
}




int solution(vector<int> picks, vector<string> minerals) {
    int answer=0;
    
    int pickcount=picks[0]+picks[1]+picks[2];
    int limit=min(pickcount*5,(int)minerals.size());

    vector<Group> groups;
    Group group;
    for (int i=0;i<limit;i++)
    {
        if (minerals[i]=="diamond")
        {
            group.diamond++;
            group.weight+=25;
        }
        else if (minerals[i]=="iron")
        {
            group.iron++;
            group.weight+=5;
        }
        else if (minerals[i]=="stone")
        {
            group.stone++;
            group.weight+=1;
        }
        if ((i+1)%5==0||i==limit-1)
        {
            groups.push_back(group);
            group=Group();
        }
    }
    
    sort(groups.begin(), groups.end(), compare);
    
   for (auto currentgroup:groups)
   {
       if (picks[0]>0)
       {
           answer+=(currentgroup.diamond+currentgroup.iron+currentgroup.stone);
           picks[0]--;
       }
       else if (picks[1]>0)
       {
           answer+=(currentgroup.diamond*5+currentgroup.iron+currentgroup.stone);
           picks[1]--;
       }
       else if (picks[2]>0)
       {
           answer+=(currentgroup.diamond*25+currentgroup.iron*5+currentgroup.stone);
           picks[2]--;
       }
   }
    
    
    
    
    return answer;
}