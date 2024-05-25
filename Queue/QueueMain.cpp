/*

ť ����
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>

#include "QueueHeader.hpp"

int main() {
    std::cout << "# - �ڷᱸ�� : ť" << std::endl;
    std::cout << "��α� : https://velog.io/@minjaek" << std::endl;
    std::cout << "����� : https://github.com/minjae-kim-github" << std::endl;
    std::cout << "�Ʒ��� �����ϴ� �ι�, ��ȭ��ȣ�� �������� �ʴ� �㱸�� ������." << std::endl << std::endl;

    Back::Queue queue;

    std::cout << "�赹��, �����, ȫ����, ȫ���� ������ Enqueue!!" << std::endl;
    queue.Enqueue("�赹��", 27, "01087654321");
    queue.Enqueue("�����", 32, "01043218765");
    queue.Enqueue("ȫ����", 24, "01012345678");
    queue.Enqueue("ȫ����", 22, "01056781234");

    std::cout << std::endl;

    std::cout << "��� Dequeue!!" << std::endl;
    while(queue.Dequeue()) {
        queue.Dequeue();
    }
    std::cout << std::endl << std::endl;

    std::cout << "�ƹ� Ű�� �Է��ϸ� ����˴ϴ�." << std::endl;
    getchar();

    return 0;
}