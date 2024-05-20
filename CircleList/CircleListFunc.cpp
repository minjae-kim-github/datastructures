/*

���� ���� ����Ʈ ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "CircleListHeader.hpp"

namespace Back {
// Data Ŭ���� �� �Լ���
Data::Data() : name(""), age(0), phoneNum("0") { std::cout << "������ ������ �Էµ��� �ʾҽ��ϴ�!!" << std::endl; }
Data::Data(const std::string rname, const int rage, std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
void Data::printData() const {
    if(name == "" || age == 0 || phoneNum == "0")
        std::cout << "�Ϻ� Ȥ�� ��ü ������ ������ �Էµ��� �ʾҽ��ϴ�!!" << std::endl;
    else {
        std::cout << '[' << name << ", " << age << ", " << phoneNum << ']' << ' ';
    }
}

// Node Ŭ���� �� �Լ���
Node::Node() : data(), next(nullptr) { }
Node::Node(const std::string rname, const int rage, const std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)), next(nullptr) { }
void Node::setNext(Node * nextNode) { next = nextNode; } // ��� -> next�� ���ڷ� ���޹��� nextNode�� ����Ű���� ����
Data * Node::getData() { return data; } // data�� �������ִ� �Լ�
Node * Node::getNext() { return next; } // next�� �������ִ� �Լ�
Node::~Node() {
    delete data; // data ����
}

// CircleList Ŭ���� �� �Լ���
CircleList::CircleList() : tail(nullptr), temp(nullptr), existCount(0) { }
void CircleList::Create(const std::string rname, const int rage, const std::string rphoneNum) {
    Node * newNode = new Node(rname, rage, rphoneNum); // �� ��� �Ҵ�
    
    if(tail == nullptr) // ���� ������ nullptr�� ����ų ���
    {
        tail = newNode; // ������ ������ ������ �� ��带 ����Ű���� ����
        newNode -> setNext(newNode); // �� ����� next�� newNode�� ����Ű���� ���� (�������� �ٽ� �ǵ��ƿ��� ����)
    }
    else { // ���� ������ �����ϴ� ��带 ����ų ���
        newNode -> setNext(tail -> getNext()); // newNode -> next�� ������ ���� ù��° ��带 ����Ű���� ����
        tail -> setNext(newNode); // ������ ���� �κ�(������ ���� ù��°)�� newNode�� ��ġ�ϵ��� ����
        tail = newNode; // ������ �� ��带 ����Ű���� ����
    }
    existCount++; // �����ϴ� ����� �� ����
}
void CircleList::PrintAll() {
    if(tail == nullptr)
        std::cout << "����� ��尡 �����ϴ�!!" << std::endl;

    temp = tail -> getNext(); // cur�� ������ ���� ���(������ ù ���)�� ����Ű���� ����

    for(int i = 0; i < existCount; i++) {
        temp -> getData() -> printData(); // cur�� ����Ű�� �ִ� ��忡 ����� �������� ���
        temp = temp -> getNext(); // cur�� ���� ��带 ����Ű���� ����
    }
}
void CircleList::Delete(const int target) {
    if(target <= 0 || target > existCount) { // ���� ���޹��� Ÿ�� ���ڰ� �߸��� ������ ���
        std::cout << "Ÿ�� ���ڴ� 1���� " << existCount << "������ �Է��Ͻ� �� �ֽ��ϴ�!!" << std::endl;
        return;
    }

    if(existCount <= 0) { // �� �ȿ� ����� ��尡 ���� ���
        std::cout << "����� ��尡 �����ϴ�!!" << std::endl;
        return;
    }

    // delNode�� ����� ���ؼ� delNode�� ����Ű�� ��, �� ��带 ������Ѿ� �ϱ⿡, �ϴ��� ������ ����Ű�� ���(���� ���� ������ �κ�)�� ����Ű���� ����
    temp = tail;
    // ������ ��带 ����Ű�� ���� ����, �ϴ��� ������ ����Ű�� ����� ���� ���(���� ���� ù �κ�)�� �⸮Ű���� ����
    Node * delNode = tail -> getNext();  

    if(existCount == 1) { // �� �ȿ� ����� ��尡 �ϳ��� ���� ���
        tail = nullptr; // ���� ���� nullptr�� ����Ű���� ����
    } else {
        for(int i = 1; i < target; i++) { // temp�� ������ ����� ���� ��带, delNode�� ������ ��带 �⸮Ű���� ����
            temp = delNode;
            delNode = delNode -> getNext();
        }
        temp -> setNext(delNode -> getNext()); // delNode�� ����Ű�� ����� ��, �� ��带 ���������

        if(delNode == tail) { // ���� ������ ��尡 ������ ����Ű�� ���(��, ���� ������ �κ��� �����ϰ��� �� ���)���
            tail = temp; // ������ ������ ����� ���� ��带 ����Ű���� ����
        }
    }

    delete delNode; // ��� ����
    existCount--; // �����ϴ� ����� �� ����
    std::cout << "���� ����!!" << std::endl;   
}
}