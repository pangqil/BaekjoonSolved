#include <string>
#include <vector>

using namespace std;

char wordlist[5]={'A','E','I','O','U'};
int dfs(string current, string target,int& count);

int solution(string word) {
    int count=0;
    dfs("", word,count);
    return count;
}
//A - 1 AA -2 AAA -3 AAAA -4 AAAAA -5 AAAAE - 6
int dfs(string current, string target,int& count)
{
    if (current==target) return count;
    if (current.length()==5) return -1;
    
    for (int i=0;i<5;i++)
    {
        count++;
        int result=dfs(current+wordlist[i], target, count);
        if (result!=-1) return result;
    }
    return -1;
}