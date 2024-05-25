/*

ť ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

namespace Back { // �ڿ��� �����Ǵ� �Լ���
    class Data { // �� ���� ����� �����͵�
    private:
        std::string name;
        int age;
        std::string phoneNum;
    public:
        // ("�̸�", ����, "��ȭ��ȣ") ������ ������� Data �ʱ�ȭ
        Data(const std::string rname, const int rage, const std::string rphoneNum);
        void printData() const; // ��忡 ����� �����͸� ���
    };

    class Node {
    private:
        Data * data;
        Node * next;
    public:
        // ("�̸�", ����, "��ȭ��ȣ") ������ ������� Data ��ü ���� �� Node �ʱ�ȭ
        Node(const std::string rname, const int rage, const std::string rphoneNum);
        Data * getData(); // data�� �����ϱ� ���ؼ� �����͸� �������ִ� �Լ� ����
        Node * getNext(); // next�� �����ϱ� ���ؼ� next�� �������ִ� �Լ� ����
        Node * setNext(Node * rnext); // -> next = rnext�� �����ϰ� ����ϴ� �Լ� ����
        ~Node(); // �Ҹ���
    };

    class Queue {
    private:
        Node * front;
        Node * rear;
    public:
        Queue(); // Queue �ʱ�ȭ
        // ("�̸�", ����, "��ȭ��ȣ") ������ ������� ��带 ������ ��, ���� ���� ����
        void Enqueue(const std::string rname, const int rage, const std::string rphoneNum);
        /* ���� ���� ����� ����� �����͸� ����� ��, ���� (��, ���Լ���),
        ���� ������ ����� ��尡 ���� ��� false ��ȯ, ���� ������ ����� ����� �����͸� ����ϰ� ���� ������ �� true ��ȯ */
        bool Dequeue();
    };
}