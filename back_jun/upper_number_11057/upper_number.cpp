#include <iostream>
#define MOD 10007

using namespace std;

int n;
int dp[100000][10];
int main(){
	cin >> n;
	for(int i = 0; i < 10; i++){
		dp[1][i] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k <= j; k++){
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}
	int sum = 0;
	for(int j =0; j < 10; j++){
		sum += dp[n][j] %MOD;
	}
	cout << sum % MOD<< "\n";
}
