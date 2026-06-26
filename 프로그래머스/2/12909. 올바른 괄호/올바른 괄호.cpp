#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    int count=0;
    
    for (auto c:s)
    {
        count++;
        if (c=='(')
        {
            st.push(c);
        }
        else if (c==')')
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    
    if (st.empty()) 
        return true;
    else
    {
        return false;
    }
}

int main()
{
    bool answer=solution("(()(");
    if (answer)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}