/**
 * 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오
 * 1. 길이가 짧은 것 부터
 * 2. 길이가 같으면 사전 순서대로
 */

#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n;

int getSum(string str) {
  int length = str.length(), sum = 0;
  for(int i = 0; i < length; i++) {
    // 숫자인 경우에 더하기
    // if(str[i] - '0' <= 9 && str[i] - '0' >= 0) {
    if ('0' <= str[i] && str[i] <= '9') {
      sum += str[i] - '0';
    }
  }
  printf("%d", sum);
  return sum;
}

bool compare(string a, string b) {
  // 길이가 짧은 순서 우선
  if(a.length() < b.length()) {
    return 1;
  } else if(a.length() > b.length()) {
    return 0;
  } else {
    int aSum = getSum(a);
    int bSum = getSum(b);
    if(aSum != bSum) {
      return aSum < bSum;
    } else {
      return a < b;
    }
  }
}

int main(void) {
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n, compare);

  for(int i = 0; i < n; i++) {
    if(i > 0 && a[i] == a[i - 1]) {
      continue;
    } else {
      cout << a[i] << '\n';
    }
  }

  return 0;
}