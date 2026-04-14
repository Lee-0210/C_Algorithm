#include <stdio.h>
/**
  첫째 줄에 수의 개수 N이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
 */

int array[1001];

int main(void) {
  int number, i, j, min, index, temp;
  scanf("%d", &number);
  for(i = 0; i < number; i++) {
    scanf("%d", &array[i]);
  }
  for(i = 0; i < number; i++) {
    min = 1001;
    for(j = i; j < number; j++) {
      if(min > array[j]) {
        min = array[j];
        index = j;
      }
    }
    temp = array[i];
    array[i] = array[index];
    array[index] = temp;
  }
  for(i = 0; i < number; i++) {
    printf("%d\n", array[i]);
  }
}