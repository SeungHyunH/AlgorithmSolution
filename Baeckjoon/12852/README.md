# [백준]12852 - 1만들기 2

- https://www.acmicpc.net/problem/12852

- 이번문제는 옛날에 풀었던 1만들기의 dp추적문제였다.

  - https://www.acmicpc.net/problem/1463

- dp개념은 알고있었는데 오랜만에 dp문제를 풀어서 그런지 바로 떠오르지가 않았다.

- DP(Dynamic Programming) : 큰 문제를 작은문제로 나눠서 푸는 알고리즘

- 점화식 min(DP[i],DP[i/2]+1) 으로 최단거리를 업데이트한다. 이 때 DP를 추적해서 답을 출력하기 위해 DP[i] > DP[i/2]+1 라면 dp가아닌 ans에 추가한다. 