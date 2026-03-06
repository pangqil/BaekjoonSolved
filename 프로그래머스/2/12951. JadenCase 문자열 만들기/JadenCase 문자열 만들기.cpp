#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer=s;
    bool newword=true;
    for(int i=0;i<answer.length();i++){
        if(s[i]==' '){
            newword=true;
        }
        else if(newword){
            newword=false;
            if(islower(answer[i])){
                answer[i]=toupper(answer[i]);
            } 
        }
        else{
            if(isupper(answer[i])){
                answer[i]=tolower(answer[i]);
            }
        }
    }
    return answer;
}