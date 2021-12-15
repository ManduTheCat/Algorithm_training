#include <iostream>

using namespace std;

int n;
int count;
void dp(int n, int num){
	// n -1 은 n 보다 작거나 같은 수가오는게 가능하다.
	if(n == 0){
		return;
	}
	for(int i =0; i < 10; i++){
		if(i <= num){
			count++;

			dp(n -1, i);
		}
	}

}
int main(){
	cin >> n;
	dp(1, 9);
	cout << count <<"\n";

}
