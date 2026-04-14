#include <stdio.h>
/**
 *  - 버블 정렬
 *  힙 트리 구조를 이용하는 정렬 방법
 */

int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void) {
  // 전체 트리 구조를 최대 힙 구조로 바꾼다.
  for(int i = 0; i < number; i++) {
    int c = i;
    do {
      int root = (c - 1) / 2;
      printf("%d 번째 root : %d \n", i+1, root);
      if(heap[root] < heap[c]) {
        int temp = heap[root];
        heap[root] = heap[c];
        heap[c] = temp;
      }
      c = root;
    } while(c != 0);
  }

  // 처음 힙 구조
  for(int i = 0; i < number; i++) {
    printf("%d ", heap[i]);
  }
  printf("\n");

  // 크기를 줄여가면서 반복적으로 힙을 구성
  for(int i = number - 1; i >= 0; i--) {
    int temp = heap[0];
    heap[0] = heap[i];
    heap[i] = temp;
    int root = 0;
    int c;
    do {
      c = 2 * root + 1;
      // 자식 중에 더 큰 값을 찾기
      if(heap[c] < heap[c + 1] && c < i - 1) {
        c ++;
      }
      // 루트보다 자식이 더 크다면 교환
      if(c < i && heap[root] < heap[c]) {
        int temp = heap[root];
        heap[root] = heap[c];
        heap[c] = temp;
        }
        root = c;
    } while(c < i);
  }
  for(int i = 0; i < number; i++) {
    printf("%d ", heap[i]);
  }
}