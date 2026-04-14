/**
 * - 서로소 집합 알고리즘
 * : 합집합 찾기라는 의미를 가진 알고리즘이다.
 */

#include <stdio.h>

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
  if(parent[x] == x) return x;
  return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a < b) parent[b] = a;
  else parent[a] = b;
}

// 같은 부모를 가지는지 확인
bool findParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a == b) return true;
  return false;
}

int main(void) {
  int parent[11];
  for(int i = 0; i <= 10; i++) {
    parent[i] = i;
    printf("%d ", parent[i]);
  }

  unionParent(parent, 1, 2);
  unionParent(parent, 2, 3);
  unionParent(parent, 3, 4);

  unionParent(parent, 5, 6);
  unionParent(parent, 6, 7);
  unionParent(parent, 7, 8);
  printf("5의 부모 노드는 : %d\n", getParent(parent, 5));
  printf("1과 5는 열결되어 있나요? %d\n", findParent(parent, 1, 5));
}