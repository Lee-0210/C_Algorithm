/**
 * 플로이드 와샬 알고리즘
 * : 모든 정점에서 모든 정점으로의 최단 경로를 구하는 알고리즘
 */

#include <stdio.h>

int number = 4;
int INF = 100000000;

// 자료 배열을 초기화
int a[4][4] = {
  {0, 5, INF, 8},
  {7, 0, 9, INF},
  {2, INF, 0, 4},
  {INF, INF, 3, 0}
};

void floydWarshall() {
  // 결과 그래프를 초기화
  int d[number][number];
  for(int i = 0; i < number; i++) {
    for(int j = 0; j < number; j++) {
      d[i][j] = a[i][j];
    }
  }

  // 로직 전 결과 출력
  printf("로직 수행 전 : \n");
  for(int i = 0; i < number; i++) {
    for(int j = 0; j < number; j++) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }

  // k = 거쳐가는 노드
  for(int k = 0; k < number; k++) {
    // i = 출발 노드
    for(int i = 0; i < number; i++) {
      // j = 도착 노드
      for(int j = 0; j < number; j++) {
        if(d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }

  // 결과를 출력
  printf("로직 수행 후 : \n");
  for(int i = 0; i < number; i++) {
    for(int j = 0; j < number; j++) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  floydWarshall();
}