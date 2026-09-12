# `solve/`

온라인 저지 문제 풀이를 정리하는 폴더.

## 디렉터리 규칙

- `solutions/<사이트>/<난이도>/<ProblemName>.{h,cpp}` — 각 문제의 헤더/구현
  - 사이트: `programmers`, `baekjoon`, `leetcode`
  - 난이도: 사이트 표기 그대로 (예: `lv0`, `lv1`, `bronze`, `silver`, `easy`, ...)
- `solutions/<사이트>/<난이도>/<ProblemName>.README.md` — 문제 링크/난이도/풀이 노트
- `util/` — 여러 문제에서 재사용하는 헬퍼 함수
- `tests/` — 단위 테스트 (`<cassert>` 기반)
- `judge.cpp` — 로컬 디버깅용 진입점

## 새 문제 추가 절차

1. `solutions/<site>/<level>/` 에 `<ProblemName>.h` + `<ProblemName>.cpp` 추가
2. 헤더에 함수 시그니처(및 `namespace <site>::<level>`) 선언
3. `.cpp`에서 함수 구현 (`.h`만 include)
4. `solutions/<site>/<level>/<ProblemName>.README.md` 에 문제 노트 작성
5. `tests/<site>/<level>/test_<problem>.cpp` 에 단위 테스트 작성
6. 별도 CMake 수정 불필요 — `file(GLOB ...)` 가 자동 수집 (`CONFIGURE_DEPENDS`)

## 네임스페이스 / 명명 규칙

- 함수/타입: `PascalCase` (예: `AdditionOfFractions`)
- 네임스페이스: 사이트/난이도 그룹화 — `programmers::lv0`, `baekjoon::bronze` 등
- 헤더에는 `using namespace std;` 사용 금지
- 가드 명은 `SITE_LEVEL_PROBLEM_NAME_H` 형식

## 빌드 / 실행

```bash
cd <repo root>
rm -rf cmake-build-debug && mkdir cmake-build-debug && cd cmake-build-debug
cmake ..
cmake --build . --target judge
./solve/judge

# 단위 테스트
cmake --build . --target solve_tests
ctest --output-on-failure
```
