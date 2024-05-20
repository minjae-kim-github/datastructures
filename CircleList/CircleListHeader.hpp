/*

���� ���� ����Ʈ ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __CIRCLE_LIST_HEADER__
#define __CIRCLE_LIST_HEADER__

namespace Back { // �ڿ��� ��� ������ ���� �����Ǵ� �ڵ��
    class Data { // ���� ��帶�� ����� �����͵��� �����ϴ� Ŭ����
    private:
        std::string name; // �̸�
        int age; // ����
        std::string phoneNum; // ��ȭ��ȣ

    public:
        Data(); // ���� ���ڷ� �ƹ��͵� ���޹��� ������ ��, �ʱ�ȭ ("", 0, 0���� �ʱ�ȭ ��)
        // ���ڷ� �̸�, ����, ��ȭ��ȣ�� ���޹޾��� ��, �ش� ���� ������� �ʱ�ȭ
        Data(const std::string rname, const int rage, std::string rphoneNum);
        void printData() const; // Data Ŭ������ ����� ����(�̸�, ����, ��ȭ��ȣ)�� ���
    };

    class Node {
    private:
        Data * data; // ��忡 ����� ������, ���� Data Ŭ������ �����Ͽ� ����� �������� �߰�, ����, ���� ����
        Node * next; // ��忡�� ���� ���� �����ϱ� ���� �ۼ�
    public:
        Node(); // ���� ���ڷ� �ƹ��͵� ���޹��� ������ ��, �ʱ�ȭ
        // ���ڷ� �̸�, ����, ��ȭ��ȣ�� ���޹޾��� ��, �ش� ���� ������� �ʱ�ȭ
        Node(const std::string rname, const int rage, std::string rphoneNum);
        void setNext(Node * nextNode); // ���� ���� ��������ִ� �Լ�
        Data * getData(); // ������ �޾ƿ��� �Լ�
        Node * getNext(); // ����� next�� �������ִ� �Լ�
        ~Node(); // �Ҹ���
    };

    class CircleList {
    private:
        Node * tail;
        Node * temp;
        int existCount;
    public:
        CircleList(); // ������

        void Create(const std::string rname, const int rage, std::string rphoneNum); // ��带 �����ϴ� ���
        void PrintAll(); // ����� ������ ������ ��� ����ϴ� ���
        void Delete(const int target); // Ÿ�ٿ� �ִ� ��带 �����ϴ� ���
    };
}

#endif