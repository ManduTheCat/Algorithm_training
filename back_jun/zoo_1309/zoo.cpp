#include <iostream>
#include <vector>

using namespace std;

#define MOD 9901
int n;
int sol[100001][3];

int main(){
	cin >> n;
	sol[0][0] = 1;
	sol[0][1] = 1;
	sol[0][2] = 1;
	for(int i = 1; i < n; i ++){
		sol[i][0] = (sol[i -1][0] + sol[i - 1][1] + sol[i - 1][2])%MOD;
		sol[i][1] = (sol[i -1][0] + sol[i - 1][2])%MOD;
		sol[i][2] = (sol[i -1][0] + sol[i - 1][2])%MOD;
	}
	for(int i = 0; i < n; i++){
		for(int j =0; j < 3; j++){
			sol[i][j] %= MOD;
		}
	}
	int total = (sol[n-1][0] + sol[n-1][1] + sol[n-1][1])%MOD ;
	cout << total << "\n";

}
