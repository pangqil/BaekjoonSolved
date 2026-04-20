#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int SX=0;
    int SY=0;

    //0은 N, 1은 S, 2는 W, 3은 E
    for (int i=0;i<park.size();i++)
    {
        size_t found=park[i].find('S');
        if (found!=string::npos)
        {
            SX=found;
            SY=i;
            break;
        }
    }
    int curx=SX;
    int cury=SY;
    
    for (const string& route:routes)
    {
        stringstream ss(route);
        char direction;
        int distance;
        ss>>direction>>distance;
        
        int nextx=curx;
        int nexty=cury;
        bool IsMove=true;
            for (int i=0;i<distance;i++)
            {
                if (direction=='N') nexty--;
                else if (direction=='E') nextx++;
                else if (direction=='W') nextx--;
                else if (direction=='S') nexty++;
                if (nextx<0||nextx>=park[0].size()||nexty<0||nexty>=park.size()||park[nexty][nextx]=='X')
                {
                    IsMove=false;
                    break;
                }
         
           }
            if (IsMove)
            {
                curx=nextx;
                cury=nexty;
            }
        }

    return{cury,curx};
}