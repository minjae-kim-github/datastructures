/*

더블 연결 리스트 메인
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "DoubleListHeader.hpp"

int main() {
    std::cout << "# - 자료구조 : 더블 연결 리스트" << std::endl;
    std::cout << "블로그 : https://velog.io/@minjaek" << std::endl;
    std::cout << "깃허브 : https://github.com/minjae-kim-github" << std::endl;
    std::cout << "아래에 등장하는 인물, 전화번호는 실존하지 않는 허구의 정보임." << std::endl << std::endl;

    Back::DoubleList list;

    std::cout << "김돌이, 김순이만 추가하는 경우" << std::endl;
    list.Create("김돌이", 27, "01087654321");
    list.Create("김순이", 32, "01043218765");
    list.printAll();
    std::cout << std::endl << std::endl;

    std::cout << "홍돌이, 홍순이도 추가하는 경우" << std::endl;
    list.Create("홍돌이", 24, "01012345678");
    list.Create("홍순이", 22, "01056781234");
    list.printAll();
    std::cout << std::endl << std::endl;

    std::cout << "김돌이, 김순이, 홍순이를 삭제하는 경우" << std::endl;
    list.Delete(1); // 머리가 가리키는 노드를 삭제함
    list.Delete(2); // 머리, 마지막 노드가 아닌 노드를 삭제함
    list.Delete(2); // 마지막 노드를 삭제함
    list.printAll();
    std::cout << std::endl << std::endl;

    std::cout << "아무 키나 입력하면 종료됩니다." << std::endl;
    getchar();

    return 0;
}