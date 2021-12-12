#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int s;
vector <int> input;
vector <int> res;

void two_point(){
	int end = 0;
	int start = 0;
	int partial_sum =0;
	while(end <= n){
		if(partial_sum >= s){
			res.push_back(end -start);
			partial_sum -= input[start++];
		}
		else if(partial_sum  < s){
			partial_sum+= input[end++];
		}
	}
}

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		input.push_back(num);
	}

	two_point();

	if((int)res.size() == 0){
		printf("0");
	}
	else{
		int min = *min_element(res.begin(), res.end());
		printf("%d", min);
	}
}
