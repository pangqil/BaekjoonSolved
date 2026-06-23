#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;


bool compare(string a, string b)
{
    return a+b>b+a;
}

string solution(vector<int> numbers) {
 
    vector<string> strings;
    
    for (int i=0;i<numbers.size();i++)
    {
        strings.push_back(to_string(numbers[i]));
    }
  
    sort(strings.begin(), strings.end(), compare);
    if (strings[0]=="0") return "0";
    
    string answer;
    for (int i=0;i<strings.size();i++)
    {
        answer+=strings[i];
    }
    
    
    return answer;
}

//6 10 2 -> 62 610 26 