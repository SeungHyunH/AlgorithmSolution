# [백준] 4195번 : 친구 네트워크
- https://www.acmicpc.net/problem/4195
- 두개의 이름이 주어질 때 union연산을 하고, 집합의 크기를 구하는 문제
- 유니온파인드를 실행하기 위해서 string->int 로 변환할 필요성이 있다. 따라서 map을 이용해 string을 key로 int를 value로 매핑시켜 구한다.
- 각집합의 크기를 배열로 저장해서 merge할 때 더 큰 집합에 작은집합을 더한다.