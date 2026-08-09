#include <iostream>
#include <string>
#include <vector>
#include <cstring>
//6:36 -> 7:00
//begin->target
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
using namespace std;



bool compareone(string s1, string s2)
{
    int count=0;
    for (int i=0;i<s1.length();i++)
    {
        if (s1[i] != s2[i]) count++;
        if (count>1) return false;
    }
    return count==1;
}

int mindepth=100000;
int visit[50]={0};
//순열 뽑아서 true인 것만 list에 넣어서 순열돌리기
void permute(string curstr, string target, vector<string> words, int depth)
{
    if (mindepth<depth) return;
    if (curstr==target)
    {
        mindepth=min(mindepth,depth);
        return;
    }
    for (int i=0;i<words.size();i++)
    {
        if (visit[i]==1) continue;
        string word=words[i];
        if (compareone(word,curstr))
        {
            visit[i]=1;
            permute(word, target, words, depth+1);
            visit[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    // memset(visit,0,sizeof(visit));
    permute(begin,target,words,0);
    
    if (mindepth==100000) mindepth=0;
    return mindepth;
}

int main()
{
    memset(visit,0,sizeof(visit));
    solution("hit", "cog", {"hot", "dot","dog", "lot", "log"});
    cout<<"mindepth="<<mindepth<<endl;
}
