# 오르막수 11057

## 풀이
* n 번쨰 오는 숫자가 가질수 있는 경우의 수를  0 - 9 별로 생각해봄
* n 번째 0 이 가질 수 있는 경우의 수  dp[n][0] 라고 할수 있다.

|	|0	|1	|2	|3	|4	|5	|6	|7	|8	|9	|
|---|---|---|---|---|---|---|---|---|---|---|
|0	|0	|0	|0	|0	|0	|0	|0	|0	|0	|0	|
|1	|1	|1	|1	|1	|1	|1	|1	|1	|1	|1	|
|2	|1	|2	|3	|4	|5	|6	|7	|8	|9	|10	|
|3	|1	|3	|6	|10	|15	|21	|28	|36	|45	|55	|

* dp[n][2] = dp[n-1][0] + dp[n-1][1] + dp[n-1][2]
* dp[n][j] = dp[n-1][0] +...+ dp[n -1][j] 라는 점화식을 찾을 수 있다.
## 어려웠던점
* 무조건 탑다운으로 풀려다가 괜히 시간날림 실전에서 이럴 시간 없다.
* 바텀업 방식으로 규칙 찾는게 더 빠른거 같다
* 적극적으로 배열을 활용하자
* n 번쨰 오는 경우의 수를 찾고 이전 배열과 어떤 관계 있는지 생각해보자
* 모든 연산에 나머지 를 구해야했었다.