#include <iostream>
#include <vector>

int a[1000000];
std::vector<int> vc;

void PrimeSet();
void PrimeFind(int id);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    PrimeSet();

    int t;
    while (true) {
        std::cin >> t;
        if (t == 0) break;
        vc.push_back(t);
    }

    for (int id : vc) {
        PrimeFind(id);
    }
}

void PrimeFind(int id) {
    for (int i = 2; i <= id / 2; i++) {
        if (a[i] && a[id - i]) {
            std::cout << id << " = " << i << " + " << id - i << "\n";
            return;
        }
    }
    std::cout << "Goldbach's conjecture is wrong\n";
}

void PrimeSet() {
    const int k = 1000000;
    for (int i = 0; i < k; i++) a[i] = i;
    a[0] = a[1] = 0;
    for (int i = 2; i * i < k; i++) {
        if (a[i]) {
            for (int j = i * i; j < k; j += i) {
                a[j] = 0;
            }
        }
    }
}
