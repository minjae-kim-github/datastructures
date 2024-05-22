/*

���� ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "StackHeader.hpp"

namespace Back {
    // Data Ŭ���� ���� �Լ���
    Data::Data(const std::string rname, const int rage, const std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
    void Data::printData() const {
        std::cout << "[" << name << ", " << age << ", " << phoneNum << "]" << " ";
    }

    // Node Ŭ���� ���� �Լ���
    Node::Node(const std::string rname, const int rage, const std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)) { }
    Data * Node::getData() const { return data; }
    Node * Node::getNext() const { return next; }
    Node * Node::setNext(Node * rnext) { next = rnext; return next; }
    Node::~Node() { delete data; }

    // Stack Ŭ���� ���� �Լ���
    Stack::Stack() : head(nullptr) { }
    bool Stack::pop() {
        if(head == nullptr) { return false; } // ���� ����� ��尡 �� ���� ������ false�� ����
        Node * temp = head; // temp�� ù ��带 ����Ű�� ��
        temp -> getData() -> printData(); // temp(ù ��带 ����Ŵ)�� �ִ� data���� �����
        head = temp -> getNext(); // �Ӹ��� ���� temp�� �ٷ� ���� ��带 ����Ű�� �� (��, ù ���� temp�� �ٷ� ���� ��尡 ��)
        delete temp; // temp�� ����Ű�� ��ü ��� ����
        return true; // ������ �Ϸ��ϸ� true�� ����
    }
    void Stack::push(const std::string rname, const int rage, const std::string rphoneNum) {
        Node * newNode = new Node(rname, rage, rphoneNum); // newNode ��ü ����
        /* newNode�� next�� ������ �Ӹ��� ����Ű�� ���, (�� newNode ����� ���� ���� ù��° �ִ� ���)�� ����Ŵ.
        ���� ������ ��尡 �� ���� ������ ��쿡�� �Ӹ��� nullptr�� ����Ű��, �� ��� newNode�� next�� nullptr�� ����Ű�� �� */
        newNode -> setNext(head);
        head = newNode; // ���� �Ӹ��� newNode�� ����Ű�� ������ (��, newNode�� ���� ó���� ��ġ�ϰ� ��)
        std::cout << "push(" << "\"" << rname << "\"" << ", " << rage << ", \"" << rphoneNum << "\") ����!!" << std::endl;
        return;
    }
}