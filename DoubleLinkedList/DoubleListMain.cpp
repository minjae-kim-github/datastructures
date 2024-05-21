/*

���� ���� ����Ʈ ����
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "DoubleListHeader.hpp"

int main() {
    std::cout << "# - �ڷᱸ�� : ���� ���� ����Ʈ" << std::endl;
    std::cout << "��α� : https://velog.io/@minjaek" << std::endl;
    std::cout << "����� : https://github.com/minjae-kim-github" << std::endl;
    std::cout << "�Ʒ��� �����ϴ� �ι�, ��ȭ��ȣ�� �������� �ʴ� �㱸�� ������." << std::endl << std::endl;

    Back::DoubleList list;

    std::cout << "�赹��, ����̸� �߰��ϴ� ���" << std::endl;
    list.Create("�赹��", 27, "01087654321");
    list.Create("�����", 32, "01043218765");
    list.printAll();
    std::cout << std::endl << std::endl;

    std::cout << "ȫ����, ȫ���̵� �߰��ϴ� ���" << std::endl;
    list.Create("ȫ����", 24, "01012345678");
    list.Create("ȫ����", 22, "01056781234");
    list.printAll();
    std::cout << std::endl << std::endl;

    std::cout << "�赹��, �����, ȫ���̸� �����ϴ� ���" << std::endl;
    list.Delete(1); // �Ӹ��� ����Ű�� ��带 ������
    list.Delete(2); // �Ӹ�, ������ ��尡 �ƴ� ��带 ������
    list.Delete(2); // ������ ��带 ������
    list.printAll();
    std::cout << std::endl << std::endl;

    std::cout << "�ƹ� Ű�� �Է��ϸ� ����˴ϴ�." << std::endl;
    getchar();

    return 0;
}