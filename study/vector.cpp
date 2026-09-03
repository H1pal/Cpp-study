#include <iostream>
#include <vector>
using namespace std;

class MyRange {
    int start, finish;
public:
    MyRange(const int s, const int f) : start(s), finish(f) {}

    class Iterator {
        int current;
    public:
        Iterator(const int value) : current(value) {}

        int operator*() const { return current; }
        Iterator& operator++() {
            current++;
            return *this;
        }
        bool operator!=(const Iterator &other) const {
            return current != other.current;
        }
    };

    Iterator begin() const { return Iterator(start); }
    Iterator end() const { return Iterator(finish); }
};

static void vector() {
    vector<int> v; // 벡터 기본 선언
    vector<int> v2(5); // 사이즈는 5, 모두 0 값으로 초기화
    vector<int> v3(5, 1); // 사이즈 5, 모두 1로 초기화
    vector<int> v4 {1, 2}; // 리스트 초기화

    cout << v.size() << " "; // size(): vector의 크기 반환
    v.push_back(1); // push_back() vector에 뒤에 값을 추가(크기 증가)
    cout << v.size() << endl;
    cout << v.at(0) << "\n\n"; // at(n) 또는 [n]: 인덱스 접근하기

    v.reserve(v2.size() + 1); // 메모리 할당 (성능 최적화)
    const int currentCapacity = v.capacity(); // capacity(): 현재 할당된 메모리를 반환
    cout << currentCapacity << "\n";
    for (int i = 0; i < v2.size(); i++) {
        v.push_back(i);
    }
    for (int i : v) {
        cout << i << endl;
    }

    for (int i = 0;i < 3; i++) {
        v.pop_back(); // 끝 원소 제거
    }


    v.clear(); // 모든 원소 제거
    cout << "모든 요소 제거 결과: " << v.size() << "\n";
    // v.push_back(1);
    cout << "vector 비어있는가?: " << v.empty() << "\n"; // empty() : 벡터가 비어있다면 `1`, 아니라면 `0`을 반환


    vector<int> fibo {1, 1};
    for (int i = 2; i <= 5; i++) {
        fibo.push_back(fibo.at(i - 1) + fibo.at(i - 2));
    }
    cout << fibo.front() << " " << fibo.back() << "\n";
    // front() / back(): 첫/마지막 원소에 접근

    auto startIter = fibo.begin(); // begin() : 해당 vector에서 첫 원소를 가리키는 iterable 반환
    auto endIter = fibo.end(); // end() : 해당 vector에서 마지막의 다음 원소를 가리키는 iterable 반환
    /* 실제 활용 */
    for (auto &i = startIter; i != fibo.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // 현재 `v`의 길이는 0 즉, 시작과 끝이 같으므로 1(true)
    if (v.begin() == v.end()) {
        cout << "v의 길이는 0" << '\n';
    } else {
        cout << "v의 길이는 1이상" << '\n';
    }

    const MyRange iter(1, 5); // iterator 만들어서 begin(),

    for (int i : iter) {
        cout << i << " ";
    }

    return 0;
}
