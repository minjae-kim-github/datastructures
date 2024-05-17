/*

���� ���� ����Ʈ ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __SINGLE_LINKED_LIST_HEADER__
#define __SINGLE_LINKED_LIST_HEADER__

namespace Back { // �ڿ��� �����Ǵ� ��ɵ�
class Data {
private:
// �Ʒ��� �� ��帶�� ������ �����͵��� ���� (�Ʒ��� ����)
    std::string name;
    int age;
public:
    Data(); // �ʱ�ȭ �Լ�
    void insertName(const std::string& rname); // �̸��� �����ϴ� �Լ�
    void insertAge(const int rage); // ���̸� �����ϴ� �Լ�
    std::string getName() const; // ����� �̸��� ��ȯ�޴� �Լ�
    int getAge() const; // ����� ���̸� ��ȯ�޴� �Լ�
};

class Node {
private:
    Data * data; // �� ��帶�� Data ��� Ŭ���� ������ �����ϱ� ����
    Node * next; // ���� ���� ������ �� �ֵ��� �ۼ�
public:
    Node(); // �ʱ�ȭ �Լ�
    void insertData(const std::string& rname, const int rage); // ������ �Է� �Լ�
    void SetNext(Node * nextNode); // ���� ���� ��������ִ� �Լ�
    Node * GetNext(); // ���� ��� ������ �޾ƿ��� �Լ�
    Data * getData(); // ������ �޾ƿ��� �Լ�
};

class LinkedList {
private:
    Node * head;
    Node * tail;
    Node * cur;
    int existCount; // ���� �����ϴ� ����� ���� �����ϱ� ���� ����
public:
    LinkedList();

    void Create(const std::string& rname, const int rage); // ��带 �����ϴ� ���
    void Print(const int target); // Ư�� ��ȣ�� ����� ����� ������ ����ϴ� ���
    void PrintAll(); // ����� ������ ������ ��� ����ϴ� ���
    void Delete(const int target); // Ư�� ��ȣ�� ����� ��带 �����ϴ� ���
    void DeleteAll(); // ��� ��带 �޸𸮿��� ������Ű�� ���
};
}

#endif