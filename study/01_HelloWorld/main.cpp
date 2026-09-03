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

using namespace h2;

int main() {
    func1();
    func2();
    func3();
    // hello();
    //
    // 오류 발생: header1과 header2에 이름이 같은 함수가 있기 때문에
    // 두 헤더 파일 모두 using namespace할 시에 실행할 함수에 대하여 `모호한 호출(ambiguous call) 에러` 발생
    // => 서로 매개변수의 타입과 개수를 다르게 두면 예방 가능

    std::cout << "Hello main World!!" << std::endl;
}