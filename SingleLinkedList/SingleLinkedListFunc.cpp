/*

단일 연결 리스트 펑션
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include <string>
#include "SingleLinkedListHeader.hpp"

namespace Back {
    Data::Data() : name(""), age(0) { }
    void Data::insertName(const std::string& rname) {
        name = rname;
    }
    void Data::insertAge(const int rage) {
        age = rage;
    }

    std::string Data::getName() const { return name; }
    int Data::getAge() const { return age; }

    Node::Node() : data(nullptr), next(nullptr) { };
    void Node::insertData(const std::string& rname, const int rage)
    {
        if(data == nullptr) data = new Data();
        data -> insertName(rname); // data에 이름 입력
        data -> insertAge(rage); // data에 나이 입력
    }
    void Node::SetNext(Node * nextNode) { next = nextNode; }
    Node* Node::GetNext() { return next; }
    Data* Node::getData() { return data; }

    // head에 더미 노드 생성
    LinkedList::LinkedList() : head(new Node()), tail(nullptr), cur(nullptr), existCount(0) { head -> SetNext(nullptr); };

    void LinkedList::Create(const std::string& rname, const int rage) {
        Node * newNode = new Node; // 새 노드 생성
        newNode -> insertData(rname, rage); // 새 노드에 데이터 입력

        if(head->GetNext() == nullptr) { // 첫 번째 노드인 경우
            head -> SetNext(newNode);
            tail = newNode;
        } else { // 이미 노드가 있는 경우
        Node * temp = head;
        while(temp -> GetNext() != nullptr) { // 마지막 노드까지 이동
            temp = temp->GetNext();
        }
        temp -> SetNext(newNode); // 마지막 노드에 새 노드 연결
        tail = newNode;
        }
        existCount++;
    }

    // 특정 번호에 저장된 노드의 정보를 출력하는 기능
    void LinkedList::Print(const int target) {
        Node* temp = head->GetNext(); // head 다음 노드부터 시작
        int count = 0;

        while(temp != nullptr && count < target) { // target 위치까지 이동
            temp = temp->GetNext();
            count++;
        }

        if(temp != nullptr && count == target) { // target 노드를 찾은 경우
            // temp가 가리키는 노드의 데이터 출력
            std::cout << "이름: " << temp -> getData() -> getName() << ", 나이: " << temp -> getData() -> getAge() << std::endl;
        } else {
            std::cout << "타겟이 존재하지 않습니다!!" << std::endl;
        }
    }

    // 저장된 노드들의 정보를 모두 출력하는 기능
    void LinkedList::PrintAll() {
        Node* temp = head->GetNext(); // head 다음 노드부터 시작

        while(temp != nullptr) { // 모든 노드를 순회
            // temp가 가리키는 노드의 데이터 출력
            std::cout << "이름: " << temp->getData()->getName() << ", 나이: " << temp->getData()->getAge() << std::endl;
            temp = temp->GetNext();
        }
    }

    void LinkedList::Delete(const int target) {
        Node* temp = head;
        Node* delNode = nullptr;
        int count = 0;

        while(temp->GetNext() != nullptr && count < target) { // target 바로 이전 위치까지 이동
            temp = temp->GetNext();
            count++;
        }

        if(temp->GetNext() != nullptr && count == target) { // target 노드를 찾은 경우
            delNode = temp->GetNext();
            temp->SetNext(delNode->GetNext()); // target 노드를 리스트에서 제거

            if(delNode == tail) { // 삭제할 노드가 마지막 노드인 경우
                tail = temp; // tail 업데이트
            }

            delete delNode; // 메모리 해제
            existCount--;
        } else {
            std::cout << "타겟이 존재하지 않습니다!!" << std::endl;
        }
    }

    void LinkedList::DeleteAll() {
        Node* temp = head->GetNext();
        Node* delNode = nullptr;

        while(temp != nullptr) { // 모든 노드를 순회하며 삭제
            delNode = temp;
            temp = temp->GetNext();
            delete delNode; // 메모리 해제
        }

        head->SetNext(nullptr); // head 노드 초기화
        tail = nullptr; // tail 초기화
        existCount = 0;
    }
}