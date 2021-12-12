#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int s;
int input[100000];
// vector <pair<int, int>> res;
vector <int> res;

void two_point(){
	int end = 0;
	int start = 0;
	int partial_sum =0;
	while(end != n){
		if(partial_sum >= s){
			// printf("%d ", partial_sum);
			// res.push_back({start, end - 1});
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
		input[i] = num;
	}

	two_point();
	// printf("\n");

	// for(auto loop : input){
	// 	printf("%d ",loop);
	// }
	// printf("\n");
	// for(int i = 0; i < (int)res.size(); i++){
			// int first = res[i].first;
			// int second = res[i].second;
			// printf("{%d %d}", first, second);
			// printf("%d ", res[i]);
	// }
	if(res.size() == 0){
		printf("0");
	}
	else{
		int min = *min_element(res.begin(), res.end());
		printf("%d", min);
	}
}
