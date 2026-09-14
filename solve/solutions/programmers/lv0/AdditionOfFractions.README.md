# AdditionOfFractions

- 문제 번호: 120808
- 사이트: [Programmers](https://school.programmers.co.kr/learn/courses/30/lessons/120808)
- 난이도: lv0
- 폴더: `solutions/programmers/lv0/`

---

## 문제

첫 번째 분수의 분자와 분모를 뜻하는 `numer1`, `denom1`, 두 번째 분수의 분자와 분모를 뜻하는 `numer2`, `denom2`가 매개변수로 주어집니다.
두 분수를 더한 값을 기약 분수로 나타냈을 때 분자와 분모를 순서대로 담은 배열을 return하도록 하세요.

### 제한 사항

- 0 < `numer1`, `denom1`, `numer2`, `denom2` < 1,000

### 입출력

- 입력
  - `numer1`: {**int**} 첫번째 분수의 분자
  - `denom1`: {**int**} 첫번째 분수의 분모
  - `numer2`: {**int**} 두번째 분수의 분자
  - `denom2`: {**int**} 두번째 분수의 분모

- 출력
  - return: {**int[]**} 기약 분수의 분자와 분모를 순서대로 담은 배열

### 입출력 예

| numer1 | denom1 | numer2 | denom2 | return |
|:-------|:-------|:-------|:-------|:-------|
| 1 | 2 | 3 | 4 | [5, 4] |
| 2 | 3 | 4 | 5 | [22, 15] |

---

## 풀이 아이디어

1. 통분: `denom = lcm(denom1, denom2)`
2. 합: `numer = numer1 * (denom / denom1) + numer2 * (denom / denom2)`
3. 약분: `gcd(numer, denom)`으로 나눠서 기약 분수로 만든다.
4. 헬퍼는 `util::lcm`, `util::make_irreducible`로 분리.

## 복잡도

- 시간: O(log(min(a, b))) (유클리드 호제법)
- 공간: O(1)

---

## 노트

