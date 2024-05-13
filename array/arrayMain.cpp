/*

1���� �迭 ����Ʈ ����
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "arrayHeader.h"

int main(void) {
    std::cout << "# - �ڷᱸ�� : 1���� �迭 ����Ʈ" << std::endl;
    std::cout << "��α� : https://velog.io/@minjaek" << std::endl;
    std::cout << "����� : https://github.com/minjae-kim-github" << std::endl;
    std::cout << std::endl << std::endl;

    // GPT�� �ۼ����� ���� ������ �ʱ�ȭ
    srand(static_cast<unsigned int>(time(0)));

    int size, maxNum;
    bool isRunning = true; // GPT�� �������� �ڵ�
    menu::initArray(size, maxNum); // �迭 �� �ʱ�ȭ ���� �޾ƿ���

    arr::Array newArray(size, maxNum); // �ν��Ͻ� ���� �� �迭 �� �ʱ�ȭ

    while(isRunning) { // GPT�� �������� �ڵ�
        isRunning = menu::menuList(newArray); // �޴� ȣ�� �� ��� �������� ����
    }

    return 0;
}