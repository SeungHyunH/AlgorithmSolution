# 백준-1655

- https://www.acmicpc.net/problem/1655
- N번의 정수입력이 주어지는데, 입력할 때마다 중앙값을 출력
  1. 홀수번 째 입력 : 중앙값 출력
  2. 짝수번 째 입력 : 중앙의 값 두개 중 작은것을 출력



- 해결방법

  - 0~중간이전 까지를 A, 중간이후부터 B 라고 할 때 A - 중간값 - B의 형태가 된다.

  - 이 때 중앙값을 구하기 위해서는 A에서는 가장큰값을, B에서는 가장 작은값을 출력해야 한다. 따라서 A는 MaxHeap을 B는MinHeap을 사용한다.

    1. MaxHeap과 MinHeap의 top은 중앙에 위치한 값들이 된다.

    2. MinHeap.size == MaxHeap.size 또는 MinHeap+1 == MaxHeap.size 가 되어야 한다.

    3. MaxHeap.top() <= MinHeap.top() 이 항상 성립해야 한다 (A-중앙값-B의 형태가 되어야 하기 때문)

  - 2번 규칙을 만족시키기 위해 MaxHeap과 MinHeap을 번갈아가며 입력한다.

  - 3번 규칙을 만족시키기 위해 MaxHeap.top() 과 MinHeap.top()을 비교해 규칙을 만족시킨다.