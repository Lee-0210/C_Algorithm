#include <stdio.h>
/*
  - 삽입 정렬
  : '필요할 때만' 위치를 바꾸는 정렬 방법
  시간 복잡도 : O(N * N)
  : 시간 복잡도는 모두 같지만 연산 횟수는 삽입 정렬이 가장 적기 때문에 효율적인 알고리즘이다.
*/

int main(void) {
  int number = 10;
  int i, j, temp;
  int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

  for(int i = 1; i < number; i++) {
    temp = array[i];
    j = i - 1;

    while(j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }

  printf("삽입 정렬 종료. ");
  for(int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
