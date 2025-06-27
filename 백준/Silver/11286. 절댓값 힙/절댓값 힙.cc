#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b){
        if (abs(a)>abs(b)) {
            return true;
        }
        else if (abs(a)==abs(b)) {
            if (a>b) {
                return true;
            }
            else return false;
        }
        return false;
    }
};

int main() {
    int n,x;

    priority_queue<int, vector<int>, cmp> q;

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        if (x==0)
        {
            if (q.empty()) {
               cout<<"0"<<endl;;
            }
            else if (!q.empty())
            {
                cout<<q.top()<<endl;;
                q.pop();
            }
        }
        else
        {
            q.push(x);
        }
    }
}