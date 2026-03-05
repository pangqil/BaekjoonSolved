#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    string temp;
    
    int mini=numeric_limits<int>::max();
    int maxi=numeric_limits<int>::min();
    
    while (ss>>temp) {
        int n=stoi(temp); 
        if(n<mini) mini=n;
        if(n>maxi) maxi=n;
    }
    string answer=to_string(mini)+" "+to_string(maxi);
    return answer;
}