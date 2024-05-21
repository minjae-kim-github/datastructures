/*

���� ���� ����Ʈ ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __DOUBLE_LIST_HEADER__
#define __DOUBLE_LIST_HEADER__

namespace Back { // �ڿ��� ����� �����ϴ� Ŭ������
    class Data { // �� ��� �� ����� �����͸� �����ϴ� Ŭ����
    private:
        std::string name;
        int age;
        std::string phoneNum;
    public:
        // ("�̸�", ����, "��ȭ��ȣ") ������ ���ڸ� ���޹޾� �ʱ�ȭ
        Data(const std::string rname, const int rage, std::string rphoneNum);
        void printData(); // ��忡 ����� �����͵��� ����ϱ� ���� ������ �Լ�
    };

    class Node { // �� ���� �����Ǵ� ������
    private:
        Data * data;
        Node * next;
        Node * before;
    public:
        // ("�̸�", ����, "��ȭ��ȣ") ������ ���ڸ� ���޹޾� Data Ŭ������ Node Ŭ���� �ʱ�ȭ
        Node(const std::string rname, const int rage, std::string rphoneNum);
        Data * getData(); // data �������ִ� �Լ�
        Node * getNext(); // next �������ִ� �Լ�
        Node * setNext(Node * rnext); // next �������ִ� �Լ�
        Node * getBefore(); // before �������ִ� �Լ�
        Node * setBefore(Node * rbefore); // before �������ִ� �Լ�
    };

    class DoubleList {
    private:
        Node * head;
        Node * temp;
        int existCount; // ��尡 �����ϴ� ��
    public:
        DoubleList(); // �ʱ�ȭ
        // ("�̸�", ����, "��ȭ��ȣ") ������ ���ڸ� ���޹޾� Node ��ü�� ���� �����, �̸� ��������ִ� �Լ�
        void Create(const std::string rname, const int rage, std::string rphoneNum);
        void Delete(const int target); // target�� ��ġ�� ��带 �������ִ� �Լ� (���� ������ �������� 1���� �����Ѵ�.)
        void printAll(); // �����ϴ� ��� ������ ������ ��� ����ϴ� �Լ�
    };
}

#endif