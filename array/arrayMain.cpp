/*

1차원 배열 리스트 메인
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "arrayHeader.h"

int main(void) {
    std::cout << "# - 자료구조 : 1차원 배열 리스트" << std::endl;
    std::cout << "블로그 : https://velog.io/@minjaek" << std::endl;
    std::cout << "깃허브 : https://github.com/minjae-kim-github" << std::endl;
    std::cout << std::endl << std::endl;

    // GPT가 작성해준 난수 생성기 초기화
    srand(static_cast<unsigned int>(time(0)));

    int size, maxNum;
    bool isRunning = true; // GPT가 제안해준 코드
    menu::initArray(size, maxNum); // 배열 값 초기화 정보 받아오기

    arr::Array newArray(size, maxNum); // 인스턴스 생성 및 배열 값 초기화

    while(isRunning) { // GPT가 제안해준 코드
        isRunning = menu::menuList(newArray); // 메뉴 호출 및 계속 실행할지 결정
    }

    return 0;
}