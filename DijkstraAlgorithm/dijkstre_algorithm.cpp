/**
 * 다익스트라 알고리즘은 다이나믹 프로그래밍을 활용한 대표적인 최단 경로 탐색 알고리즘이다.
 * 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려주고 음의 간선을 포함할 수 없기 때문에 현실 세계에 사용하기 매우 적합하다.
 */

#include <stdio.h>

int number = 6;
int INF = 1000000000;

// 전체 그래프를 초기화
int graph[6][6] = {
  {0, 2, 5, 1, INF, INF},
  {2, 0, 3, 2, INF, INF},
  {5, 3, 0, 3, 1, 5},
  {1, 2, 3, 0, 1, INF},
  {INF, INF, 1, 1, 0, 2},
  {INF, INF, 5, INF, 2, 0}
};

bool visit[6];  // 방문한 노드
int d[6];       // 최단 거리

// 가장 최소 거리를 가지는 정점 반환
int getSmallIndex() {
  int min = INF;
  int index = 0;
  for(int i = 0; i < number; i++) {
    if(d[i] < min && !visit[i]) {
      min = d[i];
      index = i;
    }
  }
  return index;
}

// 다익스트라를 수행하는 함수
void dijkstra(int start) {
  for(int i = 0; i < number; i++) {
    d[i] = graph[start][i];
  }
  visit[start] = true;
  for(int i = 0; i < number - 2; i++) {
    int current = getSmallIndex();
    visit[current] = true;
    for(int j = 0; j < 6; j ++) {
      if(!visit[j]) {
        if(d[current] + graph[current][j] < d[j]) {
          d[j] = d[current] + graph[current][j];
        }
      }
    }
  }
}

int main(void) {
  dijkstra(0);
  for(int i = 0; i < number; i++) {
    printf("%d", d[i]);
  }
}


