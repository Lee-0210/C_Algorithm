/**
 * 백준온라인 11726 번 문제 2xn 타일링
 * : 2 * n 크기의 직사각형을 2 * 2, 2 * 1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
 */

#include <stdio.h>

int d[1001];

int dp(int x) {
  if(x == 1) return 1;
  if(x == 2) return 3;
  if(d[x] != 0) return d[x];
  return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
}

int main(void) {
  int x = 8;

  printf("%d", dp(x));

  return 0;
}