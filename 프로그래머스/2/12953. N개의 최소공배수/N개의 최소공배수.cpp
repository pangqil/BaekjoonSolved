#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int result=arr[0];
    for(int i=1;i<arr.size();i++){
        result=lcm(result, arr[i]);
    }
    return result;
}