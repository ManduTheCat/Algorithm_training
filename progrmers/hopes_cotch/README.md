## 프로그래머스 땅따먹기
### 문제 링크
* [땅따먹기](https://programmers.co.kr/learn/courses/30/lessons/12913).
### 첫풀이
```cpp
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
```
#### 풀이 의 문제점
* 바로 이전의 인덱스를 기억하지 않고 첫버째 인덱스를 기억한다.
* [[4, 3, 2, 1], [2, 2, 2, 1], [6, 6, 6, 4], [8, 7, 6, 5]] 일때 첫번째 colum 1 일때 4 2 6 8 이 아니라 4 2 6 7 을 찾는다 </br>
4 2 6 '8' 을 선택해야 하지만  계속해서 첫번째 인덱스를 기억하여 8에 해당되는 3 번 인덱스를 필터링한다.
### 개선된 풀이
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
  	int n = land.size();
    for(int i = 0; i < n - 1; i++){
        land[i + 1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i + 1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i + 1][2] += max(land[i][0], max(land[i][1], land[i][3]));
        land[i + 1][3] += max(land[i][0], max(land[i][1], land[i][2]));
    }
	answer = *max_element(land[n-1].begin(), land[n-1].end());

    return answer;
}

```
#### 해결 점
* dp 를 활용 하여 바로 이전 것 을 처리 하게 하였다
* col 이 4개인 점을 활용하여 찾아야 하는 colum 을 하드 코딩 하였다.

#### 보충 할점
* 만약 colum 이 4개 가 고정이 아닐떄를 생각하여 하드 코딩 부분을 개선해야한다.
