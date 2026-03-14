#include <string>
#include <vector>
#include <stack>

using namespace std;
bool stackcount(string ss);
void swapandpop(string& s);

int solution(string s) {
    int answer=0;
    for(int i=0;i<s.size();i++){
        swapandpop(s);
        if(stackcount(s)) answer++;
    }
    return answer;   
}
//왼쪽이면 push, 오른쪽이면 pop
bool stackcount(string ss){
    stack<char> st;
    int count=0;
    for(int i=0;i<ss.size();i++){
        if(ss[i]=='('||ss[i]=='{'||ss[i]=='['){
            st.push(ss[i]);
        }
        else{
            if(st.empty()) return false;
            char top=st.top();
            if(top=='('&&ss[i]==')'||
                top=='{'&&ss[i]=='}'||
               top=='['&&ss[i]==']'){
                st.pop();
            count++;
            }
            
        }
    
    }
    if(ss.size()==count*2){
            return true;
        }
        else {
            return false;
        }
}

void swapandpop(string& s){
    s=s.substr(1)+s[0];
}

