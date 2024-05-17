/*

단일 연결 리스트 메인
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "SingleLinkedListHeader.hpp"

int main() {
    Back::LinkedList list; // LinkedList 인스턴스 생성

    // Create 함수를 사용하여 노드 생성
    list.Create("홍돌이", 20);
    list.Create("홍순이", 20);

    // PrintAll 함수를 사용하여 모든 노드의 정보 출력
    list.PrintAll();

    // DeleteAll 함수를 사용하여 모든 노드 삭제
    list.DeleteAll();

    return 0;
}
