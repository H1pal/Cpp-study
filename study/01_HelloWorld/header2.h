//
// Created by gmlvkf282 on 26. 9. 3..
//

// 최근식 header파일 선언식: #pargma once
/*
#ifndef C__TEST_HEADER1_H
#define C__TEST_HEADER1_H
#endif C__TEST_HEADER1_H
*/
// 위를 모두 수행
#pragma once

namespace h2 {
    // 헤더 파일 내부에서 구현도 가능
    // (단, inline을 붙이지 않으면 include 시에 duplicate symbol 위험)
    inline void hello(/* int a */) { printf("hello second header\n"); }
    inline int sub(const int a, const int b) { return a - b; }
}