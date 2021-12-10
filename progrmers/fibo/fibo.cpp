#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long memo[100001];
long long fibo(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 1;
    }
    else{
        if(memo[n] == 0 && n > 0){
            memo[n] = fibo(n - 2) + fibo(n - 1);
            return memo[n];
        }
        else{
           	return memo[n];
        }
    }
}

int solution(int n) {
    int fibo_res = fibo(n);
    int answer = fibo_res %1234567;
    return answer;
}

int main(){
	cout << solution(3);

}
