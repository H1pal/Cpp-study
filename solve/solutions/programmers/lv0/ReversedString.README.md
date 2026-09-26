# ReversedString

- 문제 번호: 120822
- 사이트: [Programmers](https://school.programmers.co.kr/learn/courses/30/lessons/120822)
- 난이도: lv0
- 폴더: `solve/solutions/programmers/lv0/`

---

## 문제

문자열 `my_string`이 매개변수로 주어집니다. `my_string`을 거꾸로 뒤집은 문자열을 return하도록 하세요.

### 제한 사항

- 1 ≤ `my_string`의 길이 ≤ 1,000
- `my_string`은 영소문자로만 이루어져 있습니다.

### 입출력

- 입력
  - `my_string`: {**string**} 문자열

- 출력
  - return: {**string**} 거꾸로 뒤집힌 문자열

### 입출력 예

| my_string | return |
|:----------|:-------|
| "jaron" | "noraj" |
| "bread" | "daerb" |

---

## 풀이 아이디어

1. 문자열을 받는다.
2. `std::reverse`로 앞뒤를 뒤집는다.
3. 뒤집힌 문자열을 return 한다.

## 복잡도

- 시간: O(N) — N: 문자열 길이
- 공간: O(N) — 뒤집힌 문자열 저장 (sin-place 가능)

---

## 노트

```c++
for (int i = my_string.length()-1;i >= 0 ; i--) {
    answer += my_string[i];
}
```
- `std::reverse`함수를 사용하면 위의 코드처럼 쓰지 않아도 됨
- `std::reverse(arr.begin(), arr.end())`