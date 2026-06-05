#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    vector<string> sounds = {"aya", "ye", "woo", "ma"};
    int answer = 0;

    for (string word : babbling) {
        string prev = "";
        bool ok = true;

        while (!word.empty()) {
            bool matched = false;

            for (string s : sounds) {
                if (word.rfind(s, 0) == 0 && s != prev) {
                    word.erase(0, s.size());
                    prev = s;
                    matched = true;
                    break;
                }
            }

            if (!matched) {
                ok = false;
                break;
            }
        }

        if (ok) answer++;
    }

    return answer;
}