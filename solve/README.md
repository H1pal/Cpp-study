# `solve/`

온라인 저지 문제 풀이를 정리하는 폴더입니다.

## 디렉터리 구조

```
solve/
├── cmd.json                        # 사용자 명령어 정의
├── AGENTS.md                       # Agent 사용 규칙
├── README.md                       # 본 파일
├── solutions/                      # 문제 풀이 폴더
│   ├── programmers/
│   │   ├── ProblemTemplate.md      # README.md 작성 양식
│   │   ├── lv0/                    # Programmers lv0 문제들
│   │   │   ├── exam.h
│   │   │   ├── exam.cpp
│   │   │   ├── exam.README.md
│   │   │   └── ...
│   │   ├── lv1/
│   │   │   └── ...
│   │   └── ...
│   ├── baekjoon/bronze/
│   └── ...
├── util/                           # 재사용 헬퍼 함수
└── judge.cpp                       # 로컬 디버깅용 진입점
```

## 파일명 규칙

| 요소 | 규칙 | 예시 |
|---|---|---|
| 문제 폴더 | `<사이트>/<난이도>/<ProblemName>` | `solutions/programmers/lv0/` |
| 소스 파일 | `<ProblemName>.{h,cpp}` | `FindingMode.h`, `FindingMode.cpp` |
| 풀이 노트 | `<ProblemName>.README.md` | `FindingMode.README.md` |
| 양식 파일 | `ProblemTemplate.md` | 각 난이도 폴더 내에 하나 |

> **주의**:  모든 풀이 노트는 `.README.md` 접미사를 사용합니다.

## 새 문제 추가 절차

1. `solutions/<site>/<level>/` 디렉터리에 `<ProblemName>.h` + `<ProblemName>.cpp` 추가
2. 헤더에 함수 시그니처(및 `namespace <site>::<level>`) 선언
3. `.cpp`에서 함수 구현 (`.h`만 include)
4. **`ProblemTemplate.md`** 를 참고하여 `<ProblemName>.README.md` 작성
5. `tests/<site>/<level>/test_<problem>.cpp` 에 단위 테스트 작성
6. 별도 CMake 수정 불필요 — `file(GLOB ...)` 가 자동 수집 (`CONFIGURE_DEPENDS`)

## README.md 작성 양식

각 문제 풀이 노트는 **`ProblemTemplate.md`** 에 정의된 양식을 따릅니다.

### 양식에 포함되는 항목

| 항목 | 설명 | 필수 |
|---|---|---|
| **문제명** | 파일명과 동일한 제목 (H1) | ✓ |
| **문제 번호** | Programmers/Baekjoon 문제 고유 번호 | ✓ |
| **사이트** | 문제 링크 (Programmers, Baekjoon 등) | ✓ |
| **난이도 / 폴더** | 고정 값 | ✓ |
| **문제** | 문제 원문 + 제한 사항 + 입출력 예 | ✓ |
| **풀이 아이디어** | 단계별 핵심 로직 (번호 매김 권장) | ✓ |
| **복잡도** | 시간·공간 복잡도 | ✓ |
| **노트** | 사용자 입력 칸 | - |


### 빠른 시작

```bash
# 1. ProblemTemplate.md에서 양식을 복사
cp solutions/programmers/lv0/ProblemTemplate.md solutions/programmers/lv0/<ProblemName>.README.md

# 2. 양식을 채운다
# (문제번호, 문제 원문, 풀이 로직, 복잡도 등을 입력)
```

또는 `;sync` 명령어를 사용하면 Agent가 자동으로 README.md를 양식에 맞게 생성/수정합니다.

## 네임스페이스 / 명명 규칙

- 함수/타입: `PascalCase` (예: `AdditionOfFractions`)
- 네임스페이스: 사이트/난이도 그룹화 — `programmers::lv0`, `baekjoon::bronze` 등
- 헤더에는 `using namespace std;` 사용 금지
- 가드 명은 `SITE_LEVEL_PROBLEM_NAME_H` 형식 (예: `PROGRAMMERS_LV0_ADDITION_OF_FRACTIONS_H`)

## 빌드 / 실행

```bash
cd <repo root>
rm -rf cmake-build-debug && mkdir cmake-build-debug && cd cmake-build-debug
cmake ..
cmake --build . --target judge
./solve/judge
```

## 명령어 (자동 정리)

`cmd.json`에 정의된 명령어를 사용해 풀이 결과를 자동 정리할 수 있습니다.
사용 형식과 상세 규칙은 **`AGENTS.md`** 를 참고하세요.

| 명령어 | 대상 예시 | 설명 |
|---|---|---|
| `;sync` | `;sync` 또는 `;sync @폴더명` | README.md를 ProblemTemplate에 맞게 자동 갱신 |
| `;new` | `;new @programmers/lv0/FindingMode` | 새 문제 스캐폴드(폴더, 파일, README 양식, 테스트) 자동 생성 |
| `;review` | `;review @폴더명` | 코드 검토 및 README 보완 |
| `;list` | `;list` 또는 `;list @사이트` | 풀린 문제 목록 표 출력 |
