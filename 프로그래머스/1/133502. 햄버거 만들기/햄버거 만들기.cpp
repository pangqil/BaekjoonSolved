#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    
    int answer = 0;
    vector<int> burger_stack;
    burger_stack.reserve(ingredient.size());

    for (int item : ingredient) {
        burger_stack.push_back(item);

        if (burger_stack.size() >= 4) {
            int s = burger_stack.size();
            if (burger_stack[s - 4] == 1 &&
                burger_stack[s - 3] == 2 &&
                burger_stack[s - 2] == 3 &&
                burger_stack[s - 1] == 1) {
                
                answer++;
                
                burger_stack.pop_back();
                burger_stack.pop_back();
                burger_stack.pop_back();
                burger_stack.pop_back();
            }
        }
    }

    return answer;
}