#include <iostream>
#include <math.h>

int main() {
    int k;
    int result=1;
    k=0;
    std::cin>>k;
    for (int i=1;i<=k;i++) result*=i;
    std::cout<<result;
}