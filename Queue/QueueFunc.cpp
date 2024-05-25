/*

ť ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>

#include "QueueHeader.hpp"

namespace Back {
    // Data Ŭ���� �� �Լ���
    Data::Data(const std::string rname, const int rage, const std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
    void Data::printData() const {
        std::cout << "[" << name << ", " << age << ", " << phoneNum << "]" << " ";
    }

    // Node Ŭ���� �� �Լ���
    Node::Node(const std::string rname, const int rage, const std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)) { }
    Data * Node::getData() { return data; }
    Node * Node::getNext() { return next; }
    Node * Node::setNext(Node * rnext) { next = rnext; return next; }
    Node::~Node() {
        delete data;
    }

    // Queue Ŭ���� �� �Լ���
    Queue::Queue() : front(nullptr), rear(nullptr) { }
    void Queue::Enqueue(const std::string rname, const int rage, const std::string rphoneNum) {
        Node * newNode = new Node(rname, rage, rphoneNum);

        newNode -> setNext(nullptr); // �� ����� next�� nullptr�� ����

        if(front == nullptr) { // ���� ����� ��尡 ���� ���
            front = newNode; // front�� �� ��带 ����Ű���� ����
            rear = newNode; // rear�� �� ��带 ����Ű���� ����
        }
        else { // ���� ������ ����� ��尡 ���� ���
            rear -> setNext(newNode); // rear�� next(��, ������ ���������� ����� ����� next)�� newNode�� ����Ű���� ����
            rear = newNode; // rear�� newNode�� ����Ű���� ���� (��, ������ ���� newNode�� ��)
        }

        std::cout << "Enqueue(" << "\"" << rname << "\"" << ", " << rage << ", \"" << rphoneNum << "\") ����!!" << std::endl;
    }

    bool Queue::Dequeue() {
        if(front == nullptr) { return false; } // ���� ����� ��尡 ���� ���, false�� ��ȯ

        Node * temp = front; // ��带 �����ϱ� ���ؼ� temp ����
        front = front -> getNext(); // front�� ���� ù ����� ���� ��带 ����Ű���� ���� (��, ���� �ι�° ��尡 ù ��尡 ��)

        temp -> getData() -> printData(); // �����ϱ� ��, ��忡 ����� �����͸� ���
        delete temp; // temp�� ����Ű�� ��带 ������
        return true; // ��忡 ����� ������ ����ϰ� ������ ��, true�� ����
    }
}