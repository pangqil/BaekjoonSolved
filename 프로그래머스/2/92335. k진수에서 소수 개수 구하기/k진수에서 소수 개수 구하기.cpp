#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

string convertbit(long long n, long long k){
    string converted="";
    while(n>0){
        converted+=to_string(n%k);
        n/=k;
    }
    reverse(converted.begin(), converted.end());
    return converted;
}

bool IsPrime(long long num){
    if(num<2) return false;
    if(num==2) return true;
    if (num % 2 == 0) return false;
    for(long long i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}

long long solution(int n, int k) {
    int answer = 0;
    string st=convertbit(n, k);
    
    stringstream ss(st);
    string temp;
    
    while(getline(ss, temp, '0')){
        if(temp.empty()) continue;
        
        long long current=stoll(temp);
        
        
        if(IsPrime(current)){
            answer++;
        }
    }
    
  
    return answer;
}