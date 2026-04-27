#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int &r : reserve) {
        for (int &l : lost) {
            if (r == l) {
                r = -1;
                l = -1;
                break;
            }
        }
    }

    int answer = n;
    for (int l : lost) {
        if (l == -1) continue;
        bool lent = false;
        for (int &r : reserve) {
            if (r == l - 1 || r == l + 1) {
                r = -1;
                lent = true;
                break;
            }
        }
        if (!lent) answer--;
    }

    return answer;
}