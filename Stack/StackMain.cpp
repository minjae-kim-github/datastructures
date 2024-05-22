/*

���� ����
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include "StackHeader.hpp"

int main() {
    std::cout << "# - �ڷᱸ�� : ����" << std::endl;
    std::cout << "��α� : https://velog.io/@minjaek" << std::endl;
    std::cout << "����� : https://github.com/minjae-kim-github" << std::endl;
    std::cout << "�Ʒ��� �����ϴ� �ι�, ��ȭ��ȣ�� �������� �ʴ� �㱸�� ������." << std::endl << std::endl;

    Back::Stack stack;

    std::cout << "�赹��, �����, ȫ����, ȫ���� ������ push!!" << std::endl;
    stack.push("�赹��", 27, "01087654321");
    stack.push("�����", 32, "01043218765");
    stack.push("ȫ����", 24, "01012345678");
    stack.push("ȫ����", 22, "01056781234");

    std::cout << std::endl;

    std::cout << "��� pop!!" << std::endl;
    while(stack.pop()) {
        stack.pop();
    }
    std::cout << std::endl << std::endl;

    std::cout << "�ƹ� Ű�� �Է��ϸ� ����˴ϴ�." << std::endl;
    getchar();

    return 0;
}