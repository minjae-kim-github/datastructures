/*

���� ���� ����Ʈ ���
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
        data -> insertName(rname); // data�� �̸� �Է�
        data -> insertAge(rage); // data�� ���� �Է�
    }
    void Node::SetNext(Node * nextNode) { next = nextNode; }
    Node* Node::GetNext() { return next; }
    Data* Node::getData() { return data; }

    // head�� ���� ��� ����
    LinkedList::LinkedList() : head(new Node()), tail(nullptr), cur(nullptr), existCount(0) { head -> SetNext(nullptr); };

    void LinkedList::Create(const std::string& rname, const int rage) {
        Node * newNode = new Node; // �� ��� ����
        newNode -> insertData(rname, rage); // �� ��忡 ������ �Է�

        if(head->GetNext() == nullptr) { // ù ��° ����� ���
            head -> SetNext(newNode);
            tail = newNode;
        } else { // �̹� ��尡 �ִ� ���
        Node * temp = head;
        while(temp -> GetNext() != nullptr) { // ������ ������ �̵�
            temp = temp->GetNext();
        }
        temp -> SetNext(newNode); // ������ ��忡 �� ��� ����
        tail = newNode;
        }
        existCount++;
    }

    // Ư�� ��ȣ�� ����� ����� ������ ����ϴ� ���
    void LinkedList::Print(const int target) {
        Node* temp = head->GetNext(); // head ���� ������ ����
        int count = 0;

        while(temp != nullptr && count < target) { // target ��ġ���� �̵�
            temp = temp->GetNext();
            count++;
        }

        if(temp != nullptr && count == target) { // target ��带 ã�� ���
            // temp�� ����Ű�� ����� ������ ���
            std::cout << "�̸�: " << temp -> getData() -> getName() << ", ����: " << temp -> getData() -> getAge() << std::endl;
        } else {
            std::cout << "Ÿ���� �������� �ʽ��ϴ�!!" << std::endl;
        }
    }

    // ����� ������ ������ ��� ����ϴ� ���
    void LinkedList::PrintAll() {
        Node* temp = head->GetNext(); // head ���� ������ ����

        while(temp != nullptr) { // ��� ��带 ��ȸ
            // temp�� ����Ű�� ����� ������ ���
            std::cout << "�̸�: " << temp->getData()->getName() << ", ����: " << temp->getData()->getAge() << std::endl;
            temp = temp->GetNext();
        }
    }

    void LinkedList::Delete(const int target) {
        Node* temp = head;
        Node* delNode = nullptr;
        int count = 0;

        while(temp->GetNext() != nullptr && count < target) { // target �ٷ� ���� ��ġ���� �̵�
            temp = temp->GetNext();
            count++;
        }

        if(temp->GetNext() != nullptr && count == target) { // target ��带 ã�� ���
            delNode = temp->GetNext();
            temp->SetNext(delNode->GetNext()); // target ��带 ����Ʈ���� ����

            if(delNode == tail) { // ������ ��尡 ������ ����� ���
                tail = temp; // tail ������Ʈ
            }

            delete delNode; // �޸� ����
            existCount--;
        } else {
            std::cout << "Ÿ���� �������� �ʽ��ϴ�!!" << std::endl;
        }
    }

    void LinkedList::DeleteAll() {
        Node* temp = head->GetNext();
        Node* delNode = nullptr;

        while(temp != nullptr) { // ��� ��带 ��ȸ�ϸ� ����
            delNode = temp;
            temp = temp->GetNext();
            delete delNode; // �޸� ����
        }

        head->SetNext(nullptr); // head ��� �ʱ�ȭ
        tail = nullptr; // tail �ʱ�ȭ
        existCount = 0;
    }
}