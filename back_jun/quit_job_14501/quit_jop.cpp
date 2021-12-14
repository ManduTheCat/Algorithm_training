#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p [15];
int t [15];
int ans;
int n;

void bfs(int start, int sum){
	if(start > n){
		return;
	}
	ans = max(ans, sum);
	for(int i = start; i < n ; i++){
		bfs(i + t[i], sum + p[i]);
	}

}

int main(){

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i] >> p[i];
	}
	bfs(0,0);
	cout <<  ans << "\n";
}
