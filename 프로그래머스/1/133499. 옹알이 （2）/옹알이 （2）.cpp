#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    vector<string> sounds = {"aya", "ye", "woo", "ma"};
    int answer=0;
    
    for (string word:babbling)
    {
        int preidx=-1;
        for (int i=0;i<sounds.size();i++)
        {
            if (word.substr(0, sounds[i].length())==sounds[i]&&preidx!=i)
            {
                word.erase(0, sounds[i].length());
                preidx=i;
                i=-1;
            }
        }
       
        if (word.size()==0) answer++;
        preidx=-1;
    }
    
    return answer;
}//ayaayaa -> aya, yee, u, maa