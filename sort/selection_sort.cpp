#include <stdio.h>
/*
  - 선택정렬
  시간 복잡도 : O(N * N)
  10000건의 데이터일 경우 1억번의 연산이 필요하므로 비효율적인 알고리즘이다
*/

int main(void) {
  int i, j, min, index, temp;
  int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
  for(i = 0; i < 10; i++) {
    min = 9999;
    for(j = i; j < 10; j++) {
      if(min > array[j]) {
        min = array[j];
        index = j;
      }
    }
    temp = array[i];
    array[i] = array[index];
    array[index] = temp;
  }
  printf("%s", "선택 정렬 종료 \n");
  for(i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}