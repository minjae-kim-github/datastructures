/*

스택 펑션
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "StackHeader.hpp"

namespace Back {
    // Data 클래스 내의 함수들
    Data::Data(const std::string rname, const int rage, const std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
    void Data::printData() const {
        std::cout << "[" << name << ", " << age << ", " << phoneNum << "]" << " ";
    }

    // Node 클래스 내의 함수들
    Node::Node(const std::string rname, const int rage, const std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)) { }
    Data * Node::getData() const { return data; }
    Node * Node::getNext() const { return next; }
    Node * Node::setNext(Node * rnext) { next = rnext; return next; }
    Node::~Node() { delete data; }

    // Stack 클래스 내의 함수들
    Stack::Stack() : head(nullptr) { }
    bool Stack::pop() {
        if(head == nullptr) { return false; } // 만약 저장된 노드가 한 개도 없으면 false를 리턴
        Node * temp = head; // temp는 첫 노드를 가리키게 됨
        temp -> getData() -> printData(); // temp(첫 노드를 가리킴)에 있는 data들을 출력함
        head = temp -> getNext(); // 머리는 이제 temp의 바로 다음 노드를 가리키게 됨 (즉, 첫 노드는 temp의 바로 다음 노드가 됨)
        delete temp; // temp가 가리키는 객체 노드 삭제
        return true; // 과정을 완료하면 true를 리턴
    }
    void Stack::push(const std::string rname, const int rage, const std::string rphoneNum) {
        Node * newNode = new Node(rname, rage, rphoneNum); // newNode 객체 생성
        /* newNode의 next를 기존에 머리가 가리키던 노드, (즉 newNode 생기기 전에 제일 첫번째 있던 노드)를 가리킴.
        만약 기존에 노드가 한 개도 없었을 경우에는 머리가 nullptr을 가리키니, 이 경우 newNode의 next도 nullptr을 가리키게 됨 */
        newNode -> setNext(head);
        head = newNode; // 이제 머리가 newNode을 가리키게 설정함 (즉, newNode는 제일 처음에 위치하게 됨)
        std::cout << "push(" << "\"" << rname << "\"" << ", " << rage << ", \"" << rphoneNum << "\") 성공!!" << std::endl;
        return;
    }
}