/**
 * 소수를 구할 때엔 해당 수의 제곱근까지만 확인하면 되는 공식을 이용
 */

#include <stdio.h>
#include <math.h>

bool isPrimeNumber(int x) {
  int end = (int) sqrt(x);
  for(int i = 2; i <= end; i++) {
    if(x % i == 0) return false;
  }
  return true;
}

int main(void) {
  printf("%d", isPrimeNumber(97));
  return 0;
}