#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;
//tcount,zcount 반환
vector<int> solution(string s){
    int tcount=0;
    int zcount=0;
    
    while(s!="1"){
        int current_onelength=count(s.begin(), s.end(), '1');
        zcount+=s.length()-current_onelength;
        string temp=bitset<20>(current_onelength).to_string();
        
        for(int i=0;i<temp.length();i++){
            if(temp[i]=='1') {
                s=temp.substr(i);
                break;
            }
               
        }
        
        tcount++;
    }
    return {tcount, zcount};
}