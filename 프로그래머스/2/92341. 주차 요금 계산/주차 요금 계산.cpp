#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
//fees[기본시간, 기본요금, 단위시간, 단위 요금]
//record[시각, 차량번호, 내역]
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> timeline;
    map<string, int> totaltime;
    int BT=fees[0];
    int BF=fees[1];
    int UT=fees[2];
    int UF=fees[3];
    
    for(int i = 0; i < records.size(); i++){
        stringstream ss(records[i]);
        string token;
        
        getline(ss, token, ' ');
        int convertedtime = stoi(token.substr(0, 2)) * 60 + stoi(token.substr(3, 2));
        
        getline(ss, token, ' ');
        string carnumber = token;
        
        getline(ss, token);
        if(token == "IN"){
            timeline[carnumber] = convertedtime;
        }
        else if(token == "OUT"){
            int restedtime = timeline[carnumber];
            totaltime[carnumber] += (convertedtime - restedtime);
            timeline.erase(carnumber);
        }
    }
    
    for (auto it:timeline)
    {
        string carnumber=it.first;
        int restedtime=it.second;
        int caltime=(23*60+59)-restedtime;
        totaltime[carnumber] += caltime;
    }
    
    for (auto const&[carnumber, timesum]:totaltime)
    {
        int fee=BF;
        if (timesum>BT)
        {
            int CF=ceil(static_cast<float>(timesum-BT)/UT);
            fee+=CF*UF;
        }
        answer.push_back(fee);
    }
    
   
    
    return answer;
}