#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int convertdays(string date)
{
    stringstream ss(date);
    string token;
    int year, month, day;
    
    getline(ss, token, '.');
    year=stoi(token);
    getline(ss, token, '.');
    month=stoi(token);
    getline(ss, token, '.');
    day=stoi(token);
    
    return day+month*28+year*12*28;
}

std::vector<int> solution(std::string today, vector<string> terms, vector<string> privacies)
{
    std::vector<int> answer;
    
    int date=convertdays(today);
    map<char, int> term;
    
    for (int i=0;i<terms.size();i++)
    {
            stringstream st(terms[i]);
            char alpha;
            int num;
            st>>alpha>>num;
            term[alpha]=num;
    }
    for (int j=0;j<privacies.size();j++)
    {
        stringstream sd(privacies[j]);
        string pdate;
        char pa;
        sd>>pdate>>pa;
        
        int pdays=convertdays(pdate);
        if (date>=pdays+(term[pa]*28))
        {
            answer.push_back(j+1);
        }
    }
    return answer;
}
