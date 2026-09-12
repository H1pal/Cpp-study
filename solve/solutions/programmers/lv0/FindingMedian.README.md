# FindingMedian

- 사이트: [Programmers](https://school.programmers.co.kr/)
- 난이도: lv0
- 폴더: `solutions/programmers/lv0/`

## 문제

정수 `N`과 그 다음 `N`개의 정수를 입력받아 중앙값(median)을 구한다.

## 풀이 아이디어 (현 상태)

- 현재 구현은 `N`개의 정수를 읽어 `vector`로 반환하는 단계까지만 되어 있음.
- 중앙값 계산은 정렬 후 `arr[N/2]` (N이 홀수) / `arr[N/2-1] + arr[N/2]` 평균 (N이 짝수).
- TODO: 정렬 로직 추가 후 테스트 보강.

## 복잡도

- 입력 읽기: O(N)
- 중앙값 (정렬 포함 시): O(N log N) — `std::sort` 사용 가능
