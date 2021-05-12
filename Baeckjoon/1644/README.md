# [백준]1644번 : 소수의 연속합
- https://www.acmicpc.net/problem/1644
- n이 주어질 때 연속된 소수의 합이 n보다 큰 경우의 수를 출력하시오.
1. n까지의 소수를 구한다. //나도 이 부분은 잘 몰랐었기 때문에 따로 조사를 할 필요가 있었다.
  - "에라토스테네스의 체" 라는 알고리즘이 필요하다.
    - 간단히 설명하자면 2~n까지 배수들을 전부 제외하는 방식이다. 이미 체크한 수는 continue로 검사를 건너뛰기 때문에 계산양 자체는 엄청 줄어드는 것이다.
2. 투포인터방식을 사용한다.
  1. Sum보다 큰 경우 왼쪽수를 오른쪽으로 옮기며 다시 Sum보다 큰지 비교한다.
  2. 오른쪽 수가 소수배열의 끝까지 도착하면 탐색을 종료한다.
  3. 1번2번 둘다 아니라면 Sum에 오른쪽수를 더하고 오른쪽을 한칸 오른쪽으로 옮긴다.
  4. Sum과 n이 같다면 Count를 증가시킨다.

- 필요한 과정 자체는 많이 없어 보이는 간단한 예제처럼 보이지만, 두가지의 알고리즘이 쓰인다는 점에서 공부가 필요한 중요한 예제였다. 우선 소수를 구하는 "에라토스테네스의 체"와 투포인터 두가지나 쓰인다는 점에서 코드자체는 간단하면서도 꼭 알아야할 문제였다.