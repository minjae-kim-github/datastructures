/*

더블 연결 리스트 펑션
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include <string>
#include "DoubleListHeader.hpp"

namespace Back {
    // Data 클래스 내의 함수들
    Data::Data(const std::string rname, const int rage, std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
    void Data::printData() {
        std::cout << '[' << name << ", " << age << ", " << phoneNum << ']' << " ";
    }

    // Node 클래스 내의 함수들
    Node::Node(const std::string rname, const int rage, std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)), next(nullptr), before(nullptr) { }
    Data * Node::getData() { return data; }
    Node * Node::getNext() { return next; }
    Node * Node::setNext(Node * rnext) { next = rnext; return next; }
    Node * Node::getBefore() { return before; }
    Node * Node::setBefore(Node * rbefore) { before = rbefore; return before; }

    // DoubleList 클래스 내의 함수들
    DoubleList::DoubleList() : head(nullptr), temp(nullptr), existCount(0) { }
    void DoubleList::Create(const std::string rname, const int rage, std::string rphoneNum) {
        Node * newNode = new Node(rname, rage, rphoneNum);
        
        if(head == nullptr) { // 만약 저장된 노드가 없을 경우
            head = newNode; // 머리는 새 노드를 가리키도록 설정
        } else { // 만약 저장된 노드가 있을 경우
            head -> setBefore(newNode); // 머리가 가리키는 노드의 before가 새 노드를 가리키도록 설정
            newNode -> setNext(head); // 새 노드가 기존 노드(머리가 가리키는 노드)를 가리키도록 설정
            head = newNode; // 머리는 새 노드를 가리키도록 한 칸 이동
        }

        existCount++; // 존재하는 노드의 수 증가
        return;
    }
    void DoubleList::Delete(const int target) {
        if(target > existCount || target < 1)
        {
            std::cout << "target 인자 범위 입력 오류" << std::endl;
            return;
        }

        if(existCount < 1) {
            std::cout << "저장된 노드가 없습니다!!" << std::endl;
            return;
        } else if(existCount == 1) { // 저장된 노드가 한 개 뿐일 때
            temp = head;
            head = nullptr;
        } else {
            temp = head;
            for(int i = 0; i < target - 1; i++) {
                temp = temp -> getNext(); // temp를 다음 노드로 한 칸씩 이동
            }

            if(temp == head) { // 만약 머리가 지울려는 노드를 가리키고 있다면
                head = head -> getNext(); // 머리가 삭제 대상의 다음 노드를 가리키도록 설정
                // 머리가 가리키는 노드(여기선 첫 번째 노드)의 Before가 nullptr을 가리키도록 설정
                head -> setBefore(nullptr);
            } else if(temp -> getNext() == nullptr) { // 만약 마지막 노드를 지울려면
                temp -> getBefore() -> setNext(nullptr);
            } else {
                // temp를 지우기 전, temp의 좌, 우 노드를 서로 연결시켜줌
                temp -> getBefore() -> setNext(temp ->getNext());
                temp -> getNext() -> setBefore(temp -> getBefore());
            }
        }

        delete temp; // temp가 가리키는 노드 삭제
        existCount--; // 존재하는 노드의 수 감소
        return;
    }
    void DoubleList::printAll() {
        if(existCount < 1) {
            std::cout << "저장된 노드가 없습니다!!" << std::endl;
            return;
        }
        
        temp = head; // temp는 머리가 가리키는 노드(즉, 첫 노드)를 가리키도록 설정
        while(temp != nullptr) { // 저장된 데이터들을 모두 출력
            temp -> getData() -> printData();
            temp = temp -> getNext(); // temp가 다음 노드를 가리키도록 설정
        }

        return;
    }
}