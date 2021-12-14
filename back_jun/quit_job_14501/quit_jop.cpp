#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int T[15] = {0};
int P[15] = {0};
int ans;

void dfs(int start, int sum){
	if(start > N){
		return;
	}
	ans = max(ans, sum);
	for(int i = start; i < N; i++){
		dfs(i + T[i] ,sum +P[i]);
	}
}

int main(){
	cin >> N;
	for(int i = 0; i <N; i++){
		cin >> T[i] >> P[i];
	}
	dfs(0,0);
	cout << ans;
}
