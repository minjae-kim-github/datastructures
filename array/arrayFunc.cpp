/*

1���� �迭 ����Ʈ ���
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "arrayHeader.h"

namespace arr {
    Array::Array(int size, int maxNum) : size(size), count(0), num(new int[size]) // ������ ���� �迭 �Ҵ�
    {
        for(int i = 0; i < size; i++) {
            num[i] = (rand() % maxNum) + 1; // ������ ���� ������ ���� ���ڷ� �迭 �ʱ�ȭ
            count++;
        }
    }

    // ��ɵ��� �����ϱ� ���Ͽ� �������ִ� �Լ���
    bool Array::isArrEmpty() const { // �迭�� ��� �ִ��� Ȯ���ϴ� �Լ�
        return count == 0;
    }

    bool Array::isArrFull() const { // �迭�� �� á���� Ȯ���ϴ� �Լ�
        return count == size;
    }

    int Array::getCount() const { // ī��Ʈ ���� �޾Ƽ� �Ѱ��ִ� �Լ�
        return count;
    }

    int Array::getSize() const { // ������ ���� �޾Ƽ� �Ѱ��ִ� �Լ�
        return size;
    }

    int Array::getArrNum(int target) const { // �迭�� Ÿ�Ͽ� ����� ���� �Ѱ��ִ� �Լ�
        return num[target];
    }

    // ��ɵ��� �����ص� �Լ���
    void Array::insertArray(int target, int value) { // �迭�� ���� �����ϴ� �Լ�
        if(isArrFull() == true) { std::cout << "�̹� �迭�� ���� �������� �߰��Ͻ� �� �����ϴ�!!" << std::endl; }

        else { // gpt�� �������� ����
        // target ��ġ���� �� ĭ�� �ڷ� �̵�
        for(int i = count; i > target; i--) {
            num[i] = num[i - 1];
        }
        // target ��ġ�� ���ο� �� ����
        num[target] = value;
        // ��� ���� ����
        count++;
        }
    }
    void Array::deleteArray(int target) { // Ÿ���� ã�Ƽ� �迭���� ���������� �Լ�
        if(isArrEmpty() == true) { std::cout << "�迭�� ����� ���� �����ϴ�!!" << std::endl; }
        else {
            for(int i = target; i < count; i++) {
                num[i] = num[i + 1]; // �� ĭ�� �����
            }

            count--; // ��� ���� ����
        }
    }

    int Array::searchTarget(int value) { // �迭���� Ÿ���� ã�� ��, ����� ��ġ�� ��ȯ�ϴ� �Լ�
        if(isArrEmpty() == true) { std::cout << "�迭�� ����� ���� �����ϴ�!!" << std::endl; }
        else {
            for(int i = 0; i < count; i++) {
                if(num[i] == value) { return i; }
            }

            return -1; // ���� �迭�� �ش� Ÿ���� ������, -1�� ��ȯ
        }
    }

    void Array::updateTarget(int target, int value) { // Ư�� ��ġ�� ����� ���� ������ ������ �ٲٴ� �Լ�
        if(isArrEmpty() == true) { std::cout << "�迭�� ����� ���� �����ϴ�!!" << std::endl; }
        else {
            if(target >= 0 && target <= count) {
                num[target] = value;
            }
            else { std:: cout << "�迭�� ����� ��ġ ���� �Է��� �ּ���!!" << std::endl; }
        }
    }

    Array::~Array() {
        delete[] num;
    }
}

namespace menu {
    void initArray(int &size, int &maxNum) {
        std::cout << "# - 1���� �迭 ����Ʈ�� ���� ���� ȯ���մϴ�!!" << std::endl;
        std::cout << "�迭 �ִ� ũ�� �Է� : ";
        std::cin >> size;
        std::cout << "���� �ִ� ���� �Է� : ";
        std::cin >> maxNum;
    }

    void printArray(const arr::Array &newArray) {
        std::cout << "# - ���� �迭�� ����� ������ " << newArray.getCount() << "�̸�, �ִ� ���� ������ ������ " << newArray.getSize() << "�Դϴ�." << std::endl;
        std::cout << "���� ����� �迭�� : "; 

        for(int i = 0; i < newArray.getCount(); i++)
            std::cout << newArray.getArrNum(i) << ' ';

        std::cout << std::endl;

        return;
    }

    bool menuList(arr::Array &newArray) {
    int menu, target, value;

    std::cout << "####################" << std::endl;
    std::cout << "# - 1���� �迭 ����Ʈ ���� �޴�" << std::endl;
    printArray(newArray);
    std::cout << "1. ����: �迭�� Ư�� ��ġ�� ��Ҹ� �����մϴ�." << std::endl;
    std::cout << "2. ����: �迭���� ��Ҹ� �����ϰ�, ������ ��ҵ��� �̵���ŵ�ϴ�." << std::endl;
    std::cout << "3. �˻�: �־��� ���� �迭�� �ִ��� Ȯ���ϰ�, �� ��ġ�� ��ȯ�մϴ�." << std::endl;
    std::cout << "4. ������Ʈ: �迭�� Ư�� ��ġ�� �ִ� ���� ���ο� ������ �����մϴ�." << std::endl;
    std::cout << "9. ���α׷� ����" << std::endl;

    std::cin >> menu;

    if((menu >= 1 && menu <= 9) == false) {
        std::cout << "1���� 9������ ���ڸ� �Է��� �ּ���!!";
        return true;
    }

    switch(menu) {
        case 1:
            std::cout << "���� ������ ��ġ : ";
            std::cin >> target;
            std::cout << target << "�� �ʿ� ������ �� : ";
            std::cin >> value;
            newArray.insertArray(target, value);
            break;
        case 2:
            std::cout << "������ ���� �ִ� ��ġ : ";
            std::cin >> target;
            newArray.deleteArray(target);
            break;
        case 3:
            std::cout << "�˻��� �� : ";
            std::cin >> value;
            if(newArray.searchTarget(value) >= 0) { std::cout << newArray.searchTarget(value) << "��°�� ��ġ�մϴ�!!" << std::endl; }
            else { std::cout << "�������� �ʴ� �� �Դϴ�!!" << std::endl; }
            break;
        case 4:
            std::cout << "�ٲ� ���� �ִ� ��ġ : ";
            std::cin >> target;
            std::cout << target << "�� �ʿ� ���Ӱ� �Է��� �� : ";
            std::cin >> value;
            newArray.updateTarget(target, value);
            break;
        case 9:
            return false;
        default:
            std::cout << "�߸��� �Է��Դϴ�." << std::endl;
    }
    return true;
}
}