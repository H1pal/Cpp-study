# RemovingSpecificChar

- 문제 번호: 120826
- 사이트: [Programmers](https://school.programmers.co.kr/learn/courses/30/lessons/120826)
- 난이도: lv0
- 폴더: `solve/solutions/programmers/lv0/`

---

## 문제

문자열 `my_string`과 문자 `letter`이 매개변수로 주어질 때, `my_string`에서 `letter`를 제거한 문자열을 return 하도록 함수를 완성하세요.

### 제한 사항

- 1 ≤ `my_string`의 길이 ≤ 100
- `letter`은 길이가 1인 영문자입니다.
- `my_string`과 `letter`은 알파벳 대소문자로 이루어져 있습니다.
- 대문자와 소문자를 구분합니다.

### 입출력

- 입력
  - `my_string`: {**string**} 문자열
  - `letter`: {**string**} 제거할 문자 (길이 1)

- 출력
  - return: {**string**} `letter`를 제거한 문자열

### 입출력 예

| my_string | letter | result |
|:----------|:-------|:-------|
| "abcdef" | "f" | "abcde" |
| "BCBdbe" | "B" | "Cdbe" |

---

## 풀이 아이디어

1. 문자열 `my_string`의 각 문자를 순회한다.
2. 현재 문자가 `letter`와 같지 않으면 `answer`에 추가한다.
3. 완성된 `answer`를 return 한다.

## 복잡도

- 시간: O(N) — N: `my_string`의 길이
- 공간: O(N) — 결과 문자열 저장

---

## 노트

- `judge.cpp`에도 동일한 풀이가 들어 있습니다.
- C++에서는 조건 연산자(`!=`)로 문자 비교가 가능하여 `strcmp()` 같은 함수 없이 바로 컴파일됩니다.

```c++
for (const char i : my_string) {
    if (letter[0] != i) {
        answer += i;
    }
}
```
