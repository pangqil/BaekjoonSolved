#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    vector<string> Numbers = {
        "zero", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine"
    };

    for (int i = 0; i < Numbers.size(); ++i) {
        size_t Pos = s.find(Numbers[i]);
        while (Pos != string::npos) {
            s.replace(Pos, Numbers[i].length(), to_string(i));
            Pos = s.find(Numbers[i], Pos + 1);
        }
    }
    return stoi(s);
}