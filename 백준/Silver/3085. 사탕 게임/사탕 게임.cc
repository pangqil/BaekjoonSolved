#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<char>> mat;
int maxcandy=0;
int n;

void check();
int main() {
    cin>>n;

    mat.resize(n);
    string st;
    for (int i=0;i<n;i++) {
        cin>>st;
        for (int j=0;j<n;j++){
            mat[i].push_back(st[j]);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-1;j++) {
            swap(mat[i][j],mat[i][j+1]);
            check();
            swap(mat[i][j],mat[i][j+1]);
        }
    }

    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n;j++) {
            swap(mat[i][j],mat[i+1][j]);
            check();
            swap(mat[i][j],mat[i+1][j]);
        }
    }
    cout<<maxcandy;
}

//오른
void check() {
    for (int i=0;i<n;i++) {
        int count =1;
        for (int j=0;j<n-1;j++) {
            if (mat[i][j]==mat[i][j+1]) {
                count++;
            }
            else {
                maxcandy=max(maxcandy,count);
                count=1;
            }
        }

        maxcandy=max(maxcandy,count);
    }
    for (int j=0;j<n;j++) {
        int count =1;
        for (int i=0;i<n-1;i++) {
            if (mat[i][j]==mat[i+1][j]) {
                count++;
            }
            else {
                maxcandy=max(maxcandy,count);
                count=1;
            }
        }

        maxcandy=max(maxcandy,count);
    }
}

