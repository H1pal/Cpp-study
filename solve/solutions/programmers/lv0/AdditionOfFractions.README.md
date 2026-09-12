# AdditionOfFractions

- 사이트: [Programmers](https://school.programmers.co.kr/)
- 난이도: lv0
- 폴더: `solutions/programmers/lv0/`

## 문제

두 분수 `numer1/denom1`, `numer2/denom2`의 합을 기약 분수 형태로 반환.

## 풀이 아이디어

- 통분: `denom = lcm(denom1, denom2)`
- 합: `numer = numer1 * (denom / denom1) + numer2 * (denom / denom2)`
- 약분: `gcd(numer, denom)`으로 나눠서 기약 분수로 만든다.
- 헬퍼는 `util::lcm`, `util::make_irreducible`로 분리.

## 복잡도

- 시간: O(log(min(a, b))) (유클리드 호제법)
- 공간: O(1)
