/*

���� ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __STACK_HEADER__
#define __STACK_HEADER__

namespace Back { // �ڿ��� ��� ������ ���� �۵��ϴ� Ŭ������
    class Data { // �� ���� ����� �����͵�
    private:
        std::string name;
        int age;
        std::string phoneNum;
    public:
        // ("�̸�", ����, "��ȭ��ȣ") ������ ���ڸ� ���޹޾� �ʱ�ȭ
        Data(const std::string rname, const int rage, const std::string rphoneNum);
        void printData() const; // ��忡 ����� �����͵��� ������ִ� �Լ�
    };

    class Node {
    private:
        Data * data; // �����͸� �����ϱ� ���� ����
        Node * next;
    public:
        // ("�̸�", ����, "��ȭ��ȣ") ������ ���ڸ� ���޹޾� data ��ü ���� �� �ʱ�ȭ
        Node(const std::string rname, const int rage, const std::string rphoneNum);
        Data * getData() const; // data�� printData() �Լ��� �����ϱ� ���� ����
        Node * getNext() const; // next �ּҿ� �����ϱ� ���� ����
        Node * setNext(Node * rnext); // next�� �����ϱ� ���� ����
        ~Node(); // data ��ü �����ϴ� �Ҹ���
    };

    class Stack {
    private:
        Node * head;
    public:
        Stack(); // ������
        bool pop(); // ����� ��带 ������ �Լ�, ���� ���� �� ����� ��尡 ���� ��� false ��ȯ
        // ("�̸�", ����, "��ȭ��ȣ") ������ ���ڸ� ���޹޾� ��ü ��带 ���� ���ÿ� ����ִ� �Լ�
        void push(const std::string rname, const int rage, const std::string rphoneNum);
    };
}

#endif