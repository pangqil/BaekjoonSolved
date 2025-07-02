#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> v;


//10,20,40
//(10+20) + (30+40) -> 100 but, (10+40)+(50+20) 즉 카드의 수를 정렬순대로 합쳐야 한다는 뜻.
int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    int data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin>>data;
        q.push(data);
    }
    int bstack=0;
    int totalchange=0;
    int a,b;
    int ps=0;
    while (q.size()!=1) {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        bstack+=a+b;
        q.push(a+b);
    }
    cout<<bstack<<endl;
}

//10, 20, 30, 40, 50
//(10+20)+(30+30) -> 40,50,60  (40+50)+(90+60)