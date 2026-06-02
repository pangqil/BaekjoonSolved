#include <string>
#include <vector>
#include <numeric>

using namespace std;
int gcd(int a, int b);

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int curA=arrayA[0];
    for (int n:arrayA)
    {
        curA=gcd(curA, n);
    }
        
    int curB=arrayB[0];
    for (int n:arrayB)
    {
        curB=gcd(curB, n);
    }
    
    if (curB>1)
    {
        bool canDivide=false;
        for (int n:arrayA)
        {
            if (n%curB==0)
            {
                canDivide=true;
                break;
            }
        }
        if (!canDivide)
        {
            answer=max(answer, curB);
        }
    }
    
    if (curA>1)
    {
        bool canDivide=false;
        for (int n:arrayB)
        {
            if (n%curA==0)
            {
                canDivide=true;
                break;
            }
        }
        if (!canDivide)
        {
            answer=max(answer, curA);
        }
    }
    return answer;
}

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    vector<int> arrayA={10,17};
    vector<int> arrayB={5, 20};
    solution(arrayA, arrayB);
}