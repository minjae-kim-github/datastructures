/*

���� ���� ����Ʈ ����
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "SingleLinkedListHeader.hpp"

int main() {
    Back::LinkedList list; // LinkedList �ν��Ͻ� ����

    // Create �Լ��� ����Ͽ� ��� ����
    list.Create("ȫ����", 20);
    list.Create("ȫ����", 20);

    // PrintAll �Լ��� ����Ͽ� ��� ����� ���� ���
    list.PrintAll();

    // DeleteAll �Լ��� ����Ͽ� ��� ��� ����
    list.DeleteAll();

    return 0;
}
