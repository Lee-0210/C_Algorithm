#include <stdio.h>
/*
  - 병합 정렬
  : 병합 정렬도 '분할 정복' 방법을 채택한 알고리즘으로 평균 속도가 O(N * logN) 이다.
    다른 점은 정확히 반 씩 쪼개면서 연산하기 때문에 최악의 경우에도 O(N * logN) 을 보장할 수 있다.
*/

int number = 8;
int sorted[8]; // 정렬 배열은 반드시 전역 변수로 선언

/**
 * m : 시작점
 * n : 끝점
 */
void merge(int a[], int m, int middle, int n) {
  int i = m;
  int j = middle + 1;
  int k = m;

  // 작은 순서대로 배열에 삽입
  while(i <= middle && j <= n) {
    if(a[i] <= a[j]) {
      sorted[k] = a[i];
      i++;
    } else {
      sorted[k] = a[j];
      j++;
    }
    k++;
  }

  // 남은 데이터 삽입
  if(i > middle) {
    for(int t = j; t <= n; t++) {
      sorted[k] = a[t];
      k++;
    }
  } else {
    for(int t = i; t <= middle; t++) {
      sorted[k] = a[t];
      k++;
    }
  }

  // 정렬된 배열 삽입
  for(int t = m; t <= n; t++) {
    a[t] = sorted[t];
  }
}

void mergeSort(int a[], int m, int n) {
  // 크기가 1보다 큰 경우
  if(m < n) {
    int middle = (m + n) / 2;
    mergeSort(a, m , middle);
    mergeSort(a, middle + 1, n);
    merge(a, m, middle, n);
  }
}

int main(void) {
  int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
  mergeSort(array, 0, number - 1);
  for(int i = 0; i < number; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}