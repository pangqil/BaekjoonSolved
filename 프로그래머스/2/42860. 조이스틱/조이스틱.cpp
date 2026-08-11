#include <iostream>
#include <string>
#include <vector>

using namespace std;
//3:40
char alpha[27]={'a','b','c','d','e',
    'f','g','h','i','j',
    'k','l','m','n','o',//-> 14인 경우엔 26-14
    'p','q','r','s','t',
    'u','v','w','x','y',
    'z'};//26
int solution(string name) {
    int answer=0;
    int n=name.length();
    
    for(int i=0;i<n;i++)
    {
        int bet=name[i]-'A';
        answer+=min(bet,26-bet);
    }
    
    int move=n-1;
    for (int i=0;i<n;i++)
    {
        int next=i+1;
        while (next<n&&name[next]=='A')
        {
            next++;
        }
        move=min(move, i+i+n-next);
        move=min(move, i+(n-next)*2);
        //이걸 어캐알아
    }
    
    
    
    answer+=move;
    
    return answer;
}

int main()
{
    cout<<solution("JEROEN");
}