#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <vector<int>> input;

int main(){
	cin >> n;

	for(int i = 0; i < n; i++){
		input.push_back(vector<int>());
		for(int j = 0; j < 3; j++){
			int num;
			cin >> num;
			input[i].push_back(num);
		}
	}

	for(int i = 0; i < n - 1; i++){
		input[i+1][0] = min(input[i][1],input[i][2]) + input[i + 1][0];
		input[i+1][1] = min(input[i][0],input[i][2]) + input[i + 1][1];
		input[i+1][2] = min(input[i][1],input[i][0]) + input[i + 1][2];
	}
	int min_num = min(input[n-1][0],min(input[n-1][1], input[n-1][2]));
	cout << min_num << "\n";
}
