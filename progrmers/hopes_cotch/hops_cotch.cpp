
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int col = 4;
int res[100001][4];
vector <vector<int>> g_land;
int find_next_max (int input_i, int input_j){
    int num = 1;
    vector <int> max;
    for(int j = 0; j < 4; j++){
        if(j != input_j){
        	num = g_land[input_i + 1][j];
            max.push_back(num);
    	}
    }
    int max_num = *max_element(max.begin(), max.end());
    cout << max_num<< " ";
    return max_num;
}
int solution(vector<vector<int> > land)
{
    vector <int> max_by_i;
    g_land.assign(land.begin(), land.end());
    int answer = 0;
	int n = land.size();
    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0; j < col; j++){
    		res[i][j] = find_next_max(i,j);
        }
        cout << "\n";
    }
    int sum = 0;

    for(int j =  0; j < col; j ++){
        sum = 0;
        for(int i = 0; i < n; i++){
           sum += res[i][j];
        }
        //cout << sum << " ";
        max_by_i.push_back(sum);
    }
    for(int j = 0; j < col; j++){
        max_by_i[j] += land[0][j];
    }
    for(auto loop : max_by_i){
        cout << loop << "\n";
        }
    answer = *max_element(max_by_i.begin(), max_by_i.end());
    return answer;
}
