/*

큐 펑션
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>

#include "QueueHeader.hpp"

namespace Back {
    // Data 클래스 내 함수들
    Data::Data(const std::string rname, const int rage, const std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
    void Data::printData() const {
        std::cout << "[" << name << ", " << age << ", " << phoneNum << "]" << " ";
    }

    // Node 클래스 내 함수들
    Node::Node(const std::string rname, const int rage, const std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)) { }
    Data * Node::getData() { return data; }
    Node * Node::getNext() { return next; }
    Node * Node::setNext(Node * rnext) { next = rnext; return next; }
    Node::~Node() {
        delete data;
    }

    // Queue 클래스 내 함수들
    Queue::Queue() : front(nullptr), rear(nullptr) { }
    void Queue::Enqueue(const std::string rname, const int rage, const std::string rphoneNum) {
        Node * newNode = new Node(rname, rage, rphoneNum);

        newNode -> setNext(nullptr); // 새 노드의 next를 nullptr로 설정

        if(front == nullptr) { // 만약 저장된 노드가 없을 경우
            front = newNode; // front가 새 노드를 가리키도록 설정
            rear = newNode; // rear가 새 노드를 가리키도록 설정
        }
        else { // 만약 기존에 저장된 노드가 있을 경우
            rear -> setNext(newNode); // rear의 next(즉, 기존에 마지막으로 저장된 노드의 next)가 newNode를 가리키도록 설정
            rear = newNode; // rear가 newNode를 가리키도록 설정 (즉, 마지막 노드는 newNode가 됨)
        }

        std::cout << "Enqueue(" << "\"" << rname << "\"" << ", " << rage << ", \"" << rphoneNum << "\") 성공!!" << std::endl;
    }

    bool Queue::Dequeue() {
        if(front == nullptr) { return false; } // 만약 저장된 노드가 없을 경우, false를 반환

        Node * temp = front; // 노드를 삭제하기 위해서 temp 선언
        front = front -> getNext(); // front가 기존 첫 노드의 다음 노드를 가리키도록 설정 (즉, 기존 두번째 노드가 첫 노드가 됨)

        temp -> getData() -> printData(); // 삭제하기 전, 노드에 저장된 데이터를 출력
        delete temp; // temp가 가리키는 노드를 삭제함
        return true; // 노드에 저장된 정보를 출력하고 삭제한 후, true를 리턴
    }
}