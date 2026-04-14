/**
 * 다이나믹 프로그래밍
 * : 하나의 문제는 단 한번만 풀도록 하는 알고리즘. 한 번 푼 것을 여러 번 다시 푸는 비효율적인 알고리즘을 개선시키는 방법
 *   메모이제이션(Memoization) 이 사용된다는 점에서 분할 정복과 다르다.
 *   이미 계산한 결과는 배열에 저장함으로써 나중에 동일한 계산을 해야할 때는 저장된 값을 단순히 반환하기만 한다.
 */
#include <stdio.h>

int d[100];

// 피보나치 함수
int dp(int x) {
  if(x == 1) return 1;
  if(x == 2) return 1;
  if(d[x] != 0) return d[x];
  return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void) {
  printf("%d", dp(50));

  return 0;
}