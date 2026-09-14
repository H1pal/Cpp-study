# FindingMode

- 문제 번호: 120812
- 사이트: [Programmers](https://school.programmers.co.kr/learn/courses/30/lessons/120812)
- 난이도: lv0
- 폴더: `solutions/programmers/lv0/`

---

## 문제

정수 배열 `array`가 매개변수로 주어질 때, 최빈값을 return 하도록 함수를 완성하세요.
최빈값이 여러 개이면 -1을 return 합니다.

### 제한 사항

- 1 ≤ `array`의 길이 ≤ 100
- 0 ≤ `array`의 원소 ≤ 1,000

### 입출력

- 입력
  - `array`: {**int[]**} 정수 배열

- 출력
  - return: {**int**} 최빈값 (여러 개이면 -1)

### 입출력 예

| array | return |
|:------|:-------|
| [1, 2, 3, 3, 3, 4] | 3 |
| [1, 1, 2, 2] | -1 |

---

## 풀이 아이디어

1. `counter[1004]` 배열로 각 값의 출현 빈도를 셈.
2. 최대 빈도 `maxCount`를 갱신하며 답을 갱신.
3. 동점(`counter[i] == maxCount`) 발생 시 답을 -1로 설정.

## 복잡도

- 시간: O(N + K) — N: 배열 길이, K: 값의 범위 (1000)
- 공간: O(K) — 카운터 배열 (상수 크기 1004)

---

## 노트

