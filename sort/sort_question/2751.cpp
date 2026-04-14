#include <stdio.h>
/**
 * 첫째 줄에 수의 개수 N이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
 */

int number, data[1000001];

void quickSort(int *data, int start, int end) {
  if (start >= end) {
    return;
  }

  int key = start;
  int i = start + 1;
  int j = end, temp;
  while(i <= j) {
    while(data[i] <= data[key]) {
      i++;
    }
    while(data[j] >= data[key] && j > start) {
      j--;
    }
    if(i > j) {
      temp = data[j];
      data[j] = data[key];
      data[key] = temp;
    } else {
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
    }
    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
  }
}

int main(void) {
  scanf("%d", &number);
  for(int i = 0; i < number; i++) {
    scanf("%d", &data[i]);
  }
  quickSort(data, 0, number - 1);
  for(int i = 0; i < number; i++) {
    printf("%d\n", data[i]);
  }
}

