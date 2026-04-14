#include <stdio.h>
/*
  - 버블 정렬
  : 옆의 숫자와 반복해서 위치를 교환하는 정렬 방법
  시간 복잡도 : O(N * N)
*/

int main(void) {
  int i, j, temp;
  int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
  for(i = 0; i < 10; i++) {
    for(j = 0; j < 9 - i; j++) {
      if(array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  printf("%s", "버블 정렬 종료 \n");
  for(i = 0; i < 10; i ++) {
    printf("%d ", array[i]);
  }
}