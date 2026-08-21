#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//12:00
using namespace std;

vector<int> dist;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    //2,11,14,17,21
    sort(rocks.begin(), rocks.end());
    
    vector<int> rock;
    rock.push_back(0);
    for (auto p:rocks)
    {
        rock.push_back(p);
    }
    rock.push_back(distance);
    
    //최소거리를 하나씩 늘려보기
    //어떤 숫자 n개를 제외했을때 나오는 가장 큰 값
    //-> 어떤 숫자를 n개 제외했을때 거리의 최솟값이 가장 커지는 순간.
    int left=0;
    int mid=rock[1];
    int right=distance;
    
    //거리의 최소값이 2라고 가정하자.
    while (left<=right)
    {
        mid=(left+right)/2;
        
        int removedcount=0;
        int last=0;
    
        for (int i=1;i<rock.size();i++)
        {
            int tempdist=rock[i]-last;
            if (tempdist<mid)
            {
                removedcount++;
            }
            else if (tempdist>=mid)
            {
                last=rock[i];
            }
        }
    
    
        if (removedcount<=n)//가능
        {
            answer=mid;
            left=mid+1;
        }
        else if (removedcount>n)//불가능
        {
            right=mid-1;
        }
        
    

    }

    
    
    
    
    
    
    return answer;
}
//0,2,11,14,17,21,25
int main()
{
    cout<<solution(25, {2,14,11,21,17}, 2);
}