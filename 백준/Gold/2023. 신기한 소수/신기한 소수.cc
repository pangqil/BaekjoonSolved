#include <iostream>
#include <vector>

using namespace std;

bool IsPrime(int num);

vector<vector<int>> edge;
void DFS(int number, int jisu);
int n;

int main() {

    cin >>n;
    //2,3,5,7

    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
}
//2,3,5,7 -> 2
void DFS(int number, int jisu) {
    int result;
    if (jisu==n) {
        if (IsPrime(number))
        cout << number << endl;
        return;
    }

    for (int i=1;i<=9;i++) {
        if (i%2==0) continue;
        if (IsPrime(number*10+i)) {
            DFS(number*10+i,jisu+1);
        }
    }
}
bool IsPrime(int num) {
    for (int i=2;i<=num/2;i++) {
        if (num%i==0) {
            return false;
        }
    }
    return true;
}