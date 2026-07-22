#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i=triangle.size()-2;i>=0;i--)
    {
        for (int j=0;j<=i;j++)
        {
            int temp=max(triangle[i+1][j],triangle[i+1][j+1]);
            triangle[i][j]+=temp;
        }
    }
    
    return triangle[0][0];
}