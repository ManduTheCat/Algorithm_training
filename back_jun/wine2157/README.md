# 와인시식
## 풀이
* 2잔 까지만 연속으로 마실 수 있다.
* n 번쨰 에서 의 규칙을 찾는다
* 3가지 의 패턴이 존재한다
* dp[n] 은 n 번쨰 까지 최대 많이 마신 량이라 한다
* 첫번째 경우의 수 :	dp[n - 3] + [n - 1] + [n]
* 두번째 경우의 수 :	dp[n - 2] + [n]
* 세번째 경우의 수 :	dp[n -1]
* 첫번쨰 경우의 수는 마지막에 연속으로 두잔 을 마싲는 경우
* 세번쨰 경우의 수는 n - 1 번쟤 잔을 마시지 않는경우
* 네번쩨 경우의 수는 마지막 잔을 마시는 경우가 손해 인경우 ex(1, 200,200,1) <br> 즉, n - 1, n - 2 를 연속으로 마시고 n 번째 잔을 마시지 않는 경우 이다.

```c++

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int n;
	// 입력횟수 할당
	cin >> n;

	// 와인량 배열 선언
	int *wine = new int [n + 1];

	// dp 배열 선언
	int *dp = new int[n + 1];

	// 각 배열 초기화
	memset(wine, 0 , sizeof(int) * n + 1);
	memset(dp, 0 , sizeof(int) * n + 1);

	// 와인양 배열 입력  반복문
	for(int i = 1; i <= n; i++){
		cin >> wine[i];
	}

	// 1 번째 2번째 dp에서는 모두다 마시는게 최대량이라 각 요소의 합으로 초기화 한다
	dp[1] = wine[1];
	dp[2] = wine[2] + dp[1];

	// 1 , 2 는 초기화 했으니 dp 값 을 점화식에 따라 구하는 반복문
	for(int i = 3; i <= n; i++){
		dp[i] = max(dp[i], dp[i - 3] + wine[i] + wine[i - 1]);
		dp[i] = max(dp[i], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	// 출력
	cout << dp[n];
}
```
