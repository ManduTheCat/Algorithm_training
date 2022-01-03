#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	int *wine = new int [n + 1];
	int *dp = new int[n + 1];
	memset(wine, 0 , sizeof(int) * n + 1);
	memset(dp, 0 , sizeof(int) * n + 1);


	for(int i = 1; i <= n; i++){
		cin >> wine[i];
	}
	dp[1] = wine[1];
	dp[2] = wine[2] + dp[1];


	for(int i = 3; i <= n; i++){
		dp[i] = max(dp[i], dp[i - 3] + wine[i] + wine[i - 1]);
		dp[i] = max(dp[i], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	// for(int i = 1; i <= n;  i++){
	// 	cout << dp[i] << "\n";
	// }
	cout << dp[n];
}
