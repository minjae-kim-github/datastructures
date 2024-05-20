/*

원형 연결 리스트 펑션
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "CircleListHeader.hpp"

namespace Back {
// Data 클래스 내 함수들
Data::Data() : name(""), age(0), phoneNum("0") { std::cout << "데이터 정보가 입력되지 않았습니다!!" << std::endl; }
Data::Data(const std::string rname, const int rage, std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
void Data::printData() const {
    if(name == "" || age == 0 || phoneNum == "0")
        std::cout << "일부 혹은 전체 데이터 정보가 입력되지 않았습니다!!" << std::endl;
    else {
        std::cout << '[' << name << ", " << age << ", " << phoneNum << ']' << ' ';
    }
}

// Node 클래스 내 함수들
Node::Node() : data(), next(nullptr) { }
Node::Node(const std::string rname, const int rage, const std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)), next(nullptr) { }
void Node::setNext(Node * nextNode) { next = nextNode; } // 노드 -> next가 인자로 전달받은 nextNode를 가리키도록 설정
Data * Node::getData() { return data; } // data를 리턴해주는 함수
Node * Node::getNext() { return next; } // next를 리턴해주는 함수
Node::~Node() {
    delete data; // data 삭제
}

// CircleList 클래스 내 함수들
CircleList::CircleList() : tail(nullptr), temp(nullptr), existCount(0) { }
void CircleList::Create(const std::string rname, const int rage, const std::string rphoneNum) {
    Node * newNode = new Node(rname, rage, rphoneNum); // 새 노드 할당
    
    if(tail == nullptr) // 만약 꼬리가 nullptr을 가리킬 경우
    {
        tail = newNode; // 꼬리가 위에서 생성된 새 노드를 가리키도록 설정
        newNode -> setNext(newNode); // 새 노드의 next가 newNode를 가리키도록 설정 (원형으로 다시 되돌아오는 형태)
    }
    else { // 만약 꼬리가 존재하는 노드를 가리킬 경우
        newNode -> setNext(tail -> getNext()); // newNode -> next가 원형의 제일 첫번째 노드를 가리키도록 설정
        tail -> setNext(newNode); // 꼬리의 다음 부분(원형의 제일 첫번째)에 newNode가 위치하도록 설정
        tail = newNode; // 꼬리는 새 노드를 가리키도록 설정
    }
    existCount++; // 존재하는 노드의 수 증가
}
void CircleList::PrintAll() {
    if(tail == nullptr)
        std::cout << "저장된 노드가 없습니다!!" << std::endl;

    temp = tail -> getNext(); // cur가 꼬리의 다음 노드(원형의 첫 노드)를 가리키도록 설정

    for(int i = 0; i < existCount; i++) {
        temp -> getData() -> printData(); // cur가 가리키고 있는 노드에 저장된 정보들을 출력
        temp = temp -> getNext(); // cur가 다음 노드를 가리키도록 설정
    }
}
void CircleList::Delete(const int target) {
    if(target <= 0 || target > existCount) { // 만약 전달받은 타겟 인자가 잘못된 범위일 경우
        std::cout << "타겟 인자는 1부터 " << existCount << "까지만 입력하실 수 있습니다!!" << std::endl;
        return;
    }

    if(existCount <= 0) { // 원 안에 저장된 노드가 없는 경우
        std::cout << "저장된 노드가 없습니다!!" << std::endl;
        return;
    }

    // delNode를 지우기 위해선 delNode가 가리키는 전, 후 노드를 연결시켜야 하기에, 일단은 꼬리가 가리키는 노드(원의 제일 마지막 부분)을 가리키도록 설정
    temp = tail;
    // 삭제될 노드를 가리키기 위해 선언, 일단은 꼬리가 가리키는 노드의 다음 노드(원의 제일 첫 부분)을 기리키도록 설정
    Node * delNode = tail -> getNext();  

    if(existCount == 1) { // 원 안에 저장된 노드가 하나만 있을 경우
        tail = nullptr; // 꼬리 노드는 nullptr을 가리키도록 설정
    } else {
        for(int i = 1; i < target; i++) { // temp는 삭제될 노드의 이전 노드를, delNode는 삭제될 노드를 기리키도록 설정
            temp = delNode;
            delNode = delNode -> getNext();
        }
        temp -> setNext(delNode -> getNext()); // delNode가 가리키는 노드의 전, 후 노드를 연결시켜줌

        if(delNode == tail) { // 만약 삭제될 노드가 꼬리가 가리키는 노드(즉, 원의 마지막 부분을 삭제하고자 할 경우)라면
            tail = temp; // 꼬리를 삭제될 노드의 이전 노드를 가리키도록 설정
        }
    }

    delete delNode; // 노드 삭제
    existCount--; // 존재하는 노드의 수 감소
    std::cout << "삭제 성공!!" << std::endl;   
}
}