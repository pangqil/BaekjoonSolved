#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string form;
    cin >> form;

    vector<int> numbers;
    vector<char> operators;

    string temp = "";
    for (char ch : form) {
        if (ch == '+' || ch == '-') {
            numbers.push_back(stoi(temp));
            operators.push_back(ch);
            temp = "";
        } else {
            temp += ch;
        }
    }
    if (!temp.empty()) {
        numbers.push_back(stoi(temp));
    }

    int result = numbers[0];
    bool minus_mode = false;

    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] == '-') {
            minus_mode = true;
        }

        if (minus_mode) {
            result -= numbers[i + 1];
        } else {
            result += numbers[i + 1];
        }
    }

    cout << result << endl;
}
