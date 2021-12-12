# 부분합

## 풀이
* 투포인터 로 구현
* end 가 n 보다 작을때 while 돈다.
* interval_sum 이 s 보다 크면 start 포인트 이동
* input[start] 를 빼는 연산을 통해 start 이동 을 구현 검색했지만 참신한 아이디어이다.
* interver_sum 이 s 보다 작으면 end 포인트 이동
* s 보다 크거나 같을때 res 에 start point, end point  저장
* 마지막에 모든 순회에 불구하고 답이 없으면 0 출력

## 어려웠던점
* 투 포인터를 처음 구현하다 보니 중간에 많이 꼬였다 익숙하게 많이 구현해보아야한다.
* 마지막에 vectro res 를 int 로 형변환 을 하지 않아 sagfalt 가 떠서 이유를 찾는데 오래 결렀다. 항상 vector 의 size 는 int 로 형변환을 하자
* 처음에는 dp 문제인줄 알고 많이 돌아가다 결국 검색하였다.(ai tech 시험 문제이기도 했다.)
* 처음 토포인터 만들때 start 포인트가 end 가 다돌면 돌게 만드는 실수를 하였다. 투포인터 개념을 잘 이해 했었어야 했다.
