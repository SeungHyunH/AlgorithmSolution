# [백준] 11066번 : 파일 합치기
- https://www.acmicpc.net/problem/11066
- 생각보다 어려운 DP문제였다. 다시 풀어봐야한다. DP정의를 어떻게 해야할 지 막막해서 검색해서 풀었던 문제이다.
  - 연속된 파일 2개만 합칠 수 있다. 즉 점화식을 세워서 풀어야 하는 문제였다.(그리디X)
  - `DP[i][j]` 를 i~j까지의 파일의 최소비용이라고 했을 때 `min(dp[i][j],dp[i][k]+dp[k][j])`로 점화식을 세울 수 있다.
  - 여기서 각 파일의 크기는 더해지지 않았으므로 따로 sum배열을 만들어서 합쳐야 된다.
- 완벽하게 이해가 된 문제는 아니다. 아마 다시 풀라고 했을 때 틀릴 것 같은 문제이다. 그래서 다시 풀면서 연습해야 하는 문제이다.