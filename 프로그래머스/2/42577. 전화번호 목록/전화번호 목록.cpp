#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    int count=0;
    for (string &head : phone_book)
    {
        int headlen=head.length();
        
        for (int i=count+1;i<phone_book.size();i++)
        {
            if (phone_book[i].length()<headlen) break;
            if (phone_book[i].substr(0, headlen)!=head) break;
            
            string comparst=phone_book[i].substr(0,headlen);
            
            if (comparst==head) return false;
        }
        count++;
    }
    return true;
    
    
    
    
}

int main()
{
    cout<<solution({"115", "98765432", "1195432"});
}