/*

스택 메인
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "StackHeader.hpp"

int main() {
    std::cout << "# - 자료구조 : 스택" << std::endl;
    std::cout << "블로그 : https://velog.io/@minjaek" << std::endl;
    std::cout << "깃허브 : https://github.com/minjae-kim-github" << std::endl;
    std::cout << "아래에 등장하는 인물, 전화번호는 실존하지 않는 허구의 정보임." << std::endl << std::endl;

    Back::Stack stack;

    std::cout << "김돌이, 김순이, 홍돌이, 홍순이 순으로 push!!" << std::endl;
    stack.push("김돌이", 27, "01087654321");
    stack.push("김순이", 32, "01043218765");
    stack.push("홍돌이", 24, "01012345678");
    stack.push("홍순이", 22, "01056781234");

    std::cout << std::endl;

    std::cout << "모두 pop!!" << std::endl;
    while(stack.pop()) {
        stack.pop();
    }
    std::cout << std::endl << std::endl;

    std::cout << "아무 키나 입력하면 종료됩니다." << std::endl;
    getchar();

    return 0;
}