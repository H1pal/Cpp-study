#include <iostream>
#include "header1.h"
#include "header2.h"

/* 헤더파일 호출 방법 */

// 인터페이스를 구현
void h1::hello() {
    std::cout<<"hello fisrt world"<< std::endl;
}

static void func1() {
    // h1 이름 공간을 붙여 호출
    h1::hello();
}

// namespace 범위 내부에선 이름 공간(namespace)를 명시하지 않고 자유롭게 호출
namespace h1 {
    void func2() {
        hello(); // header1의 interface
        h2::hello(); // header2의 interface
    }
}

// using namespace를 사용하면 적연 범위에서 자유롭게 사용 가능
using namespace h1;
int func3() {
    // using namespace를 이용하면 namespace 표식을 사용하지 않아도 됨
    hello(); // header1의 hello()
    return 0;
}

namespace {
    int OnlyInThisFile() {
        std::cout<<"OnlyInThisFile"<< std::endl;
        return 0;
    }

    int only_in_this_file = 0;

}

using namespace h2;

int main() {
    /*
    01-2. 프로그램 분석하기
    */
    func1();
    func2();
    func3();
    // hello();
    //
    // 오류 발생: header1과 header2에 이름이 같은 함수가 있기 때문에
    // 두 헤더 파일 모두 using namespace할 시에 실행할 함수에 대하여 `모호한 호출(ambiguous call) 에러` 발생
    // => 서로 매개변수의 타입과 개수를 다르게 두면 예방 가능

    // std::cout: ostream 클래스의 객페 표준 출력
    // std::endl: 화면에 출력해주는 '함수' (출력 버퍼를 비우고 '\n'를 출력)
    std::cout << "Hello main World!!" << std::endl;
    std::cout << "my name is ";
    std::cout << "hee seong" << std::endl;

    OnlyInThisFile();


    /*
    01-3. C와의 공통점
    */

    // if - else, while, for, switch 등의 존재
    // C 코드가 C++ 코드에 포함되는 것은 아님
    // => C 컴파일러로 컴파일 되지만 C++ 에서는 되지 않는 요소들이 존재

    // 변수의 정의
    int i;
    char c;
    double d;
    float f;
    // 컴파일러에 따라서 한글 변수명은 사용 가능하지만 권장 X
    // 변수명 맨 앞에 대문자 X

    // 포인터: C와 돌이
    int arr[10];
    int *parr = arr;

    int a;
    int *pi = &a;

    // 반복문
    for (int i = 0;i < 10;i++) {
        std::cout<<i<<" ";
    }
    int cnt = 0;
    while (cnt <= 10) {
        std::cout<<cnt++<<std::endl;
    }

    // 입력
    // C: scanf로 변수앞에 `&`을 붙임 / 받는 데이터형을 정해야 하며, 데이터형에 따라서 인자를 다르게 주어서 입력 받아야 함
    // C++: `cin >> {변수명}` 형태로 간단 / 데이터형에 관계없이 입력 받을 수 있음

    return 0;
}