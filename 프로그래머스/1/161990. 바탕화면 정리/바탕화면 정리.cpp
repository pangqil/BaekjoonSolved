#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<string> wallpaper) {
    int minx=50, miny=50, maxx=0, maxy=0;
    vector<int> answer;
    
    for (int i=0;i<wallpaper.size();i++)
    {
        for (int j=0;j<wallpaper[0].size();j++)
        {
            if (wallpaper[i][j]=='#')
            {
                minx=min(minx, i);
                miny=min(miny, j);
                maxx=max(maxx, i);
                maxy=max(maxy, j);
            }
        }
    }
    
   
    return {minx, miny, maxx+1, maxy+1};
}




