#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothesmap;
    
    for(vector<string>& item: clothes){
        string& kinds=item[1];
        clothesmap[kinds]++;
    }    
    
    for(auto& [key, k]:clothesmap){
        answer*=(k+1);
    }
    answer=answer-1;
    
    return answer;
}