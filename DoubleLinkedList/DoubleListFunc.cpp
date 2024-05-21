/*

���� ���� ����Ʈ ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include <string>
#include "DoubleListHeader.hpp"

namespace Back {
    // Data Ŭ���� ���� �Լ���
    Data::Data(const std::string rname, const int rage, std::string rphoneNum) : name(rname), age(rage), phoneNum(rphoneNum) { }
    void Data::printData() {
        std::cout << '[' << name << ", " << age << ", " << phoneNum << ']' << " ";
    }

    // Node Ŭ���� ���� �Լ���
    Node::Node(const std::string rname, const int rage, std::string rphoneNum) : data(new Data(rname, rage, rphoneNum)), next(nullptr), before(nullptr) { }
    Data * Node::getData() { return data; }
    Node * Node::getNext() { return next; }
    Node * Node::setNext(Node * rnext) { next = rnext; return next; }
    Node * Node::getBefore() { return before; }
    Node * Node::setBefore(Node * rbefore) { before = rbefore; return before; }

    // DoubleList Ŭ���� ���� �Լ���
    DoubleList::DoubleList() : head(nullptr), temp(nullptr), existCount(0) { }
    void DoubleList::Create(const std::string rname, const int rage, std::string rphoneNum) {
        Node * newNode = new Node(rname, rage, rphoneNum);
        
        if(head == nullptr) { // ���� ����� ��尡 ���� ���
            head = newNode; // �Ӹ��� �� ��带 ����Ű���� ����
        } else { // ���� ����� ��尡 ���� ���
            head -> setBefore(newNode); // �Ӹ��� ����Ű�� ����� before�� �� ��带 ����Ű���� ����
            newNode -> setNext(head); // �� ��尡 ���� ���(�Ӹ��� ����Ű�� ���)�� ����Ű���� ����
            head = newNode; // �Ӹ��� �� ��带 ����Ű���� �� ĭ �̵�
        }

        existCount++; // �����ϴ� ����� �� ����
        return;
    }
    void DoubleList::Delete(const int target) {
        if(target > existCount || target < 1)
        {
            std::cout << "target ���� ���� �Է� ����" << std::endl;
            return;
        }

        if(existCount < 1) {
            std::cout << "����� ��尡 �����ϴ�!!" << std::endl;
            return;
        } else if(existCount == 1) { // ����� ��尡 �� �� ���� ��
            temp = head;
            head = nullptr;
        } else {
            temp = head;
            for(int i = 0; i < target - 1; i++) {
                temp = temp -> getNext(); // temp�� ���� ���� �� ĭ�� �̵�
            }

            if(temp == head) { // ���� �Ӹ��� ������� ��带 ����Ű�� �ִٸ�
                head = head -> getNext(); // �Ӹ��� ���� ����� ���� ��带 ����Ű���� ����
                // �Ӹ��� ����Ű�� ���(���⼱ ù ��° ���)�� Before�� nullptr�� ����Ű���� ����
                head -> setBefore(nullptr);
            } else if(temp -> getNext() == nullptr) { // ���� ������ ��带 �������
                temp -> getBefore() -> setNext(nullptr);
            } else {
                // temp�� ����� ��, temp�� ��, �� ��带 ���� ���������
                temp -> getBefore() -> setNext(temp ->getNext());
                temp -> getNext() -> setBefore(temp -> getBefore());
            }
        }

        delete temp; // temp�� ����Ű�� ��� ����
        existCount--; // �����ϴ� ����� �� ����
        return;
    }
    void DoubleList::printAll() {
        if(existCount < 1) {
            std::cout << "����� ��尡 �����ϴ�!!" << std::endl;
            return;
        }
        
        temp = head; // temp�� �Ӹ��� ����Ű�� ���(��, ù ���)�� ����Ű���� ����
        while(temp != nullptr) { // ����� �����͵��� ��� ���
            temp -> getData() -> printData();
            temp = temp -> getNext(); // temp�� ���� ��带 ����Ű���� ����
        }

        return;
    }
}