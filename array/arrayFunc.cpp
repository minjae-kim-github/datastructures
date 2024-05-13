/*

1차원 배열 리스트 펑션
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "arrayHeader.h"

namespace arr {
    Array::Array(int size, int maxNum) : size(size), count(0), num(new int[size]) // 생성자 동적 배열 할당
    {
        for(int i = 0; i < size; i++) {
            num[i] = (rand() % maxNum) + 1; // 지정된 범위 내에서 랜덤 숫자로 배열 초기화
            count++;
        }
    }

    // 기능들을 구현하기 위하여 보조해주는 함수들
    bool Array::isArrEmpty() const { // 배열이 비어 있는지 확인하는 함수
        return count == 0;
    }

    bool Array::isArrFull() const { // 배열이 꽉 찼는지 확인하는 함수
        return count == size;
    }

    int Array::getCount() const { // 카운트 값을 받아서 넘겨주는 함수
        return count;
    }

    int Array::getSize() const { // 사이즈 값을 받아서 넘겨주는 함수
        return size;
    }

    int Array::getArrNum(int target) const { // 배열의 타켓에 저장된 값을 넘겨주는 함수
        return num[target];
    }

    // 기능들을 구현해둔 함수들
    void Array::insertArray(int target, int value) { // 배열에 숫자 삽입하는 함수
        if(isArrFull() == true) { std::cout << "이미 배열이 가득 차버려서 추가하실 수 없습니다!!" << std::endl; }

        else { // gpt가 구현해준 로직
        // target 위치부터 한 칸씩 뒤로 이동
        for(int i = count; i > target; i--) {
            num[i] = num[i - 1];
        }
        // target 위치에 새로운 값 삽입
        num[target] = value;
        // 요소 개수 증가
        count++;
        }
    }
    void Array::deleteArray(int target) { // 타겟을 찾아서 배열에서 지워버리는 함수
        if(isArrEmpty() == true) { std::cout << "배열에 저장된 값이 없습니다!!" << std::endl; }
        else {
            for(int i = target; i < count; i++) {
                num[i] = num[i + 1]; // 한 칸씩 땡기기
            }

            count--; // 요소 개수 감소
        }
    }

    int Array::searchTarget(int value) { // 배열에서 타겟을 찾은 뒤, 저장된 위치를 반환하는 함수
        if(isArrEmpty() == true) { std::cout << "배열에 저장된 값이 없습니다!!" << std::endl; }
        else {
            for(int i = 0; i < count; i++) {
                if(num[i] == value) { return i; }
            }

            return -1; // 만일 배열에 해당 타겟이 없으면, -1을 반환
        }
    }

    void Array::updateTarget(int target, int value) { // 특정 위치에 저장된 값을 지정한 값으로 바꾸는 함수
        if(isArrEmpty() == true) { std::cout << "배열에 저장된 값이 없습니다!!" << std::endl; }
        else {
            if(target >= 0 && target <= count) {
                num[target] = value;
            }
            else { std:: cout << "배열에 저장된 위치 값만 입력해 주세요!!" << std::endl; }
        }
    }

    Array::~Array() {
        delete[] num;
    }
}

namespace menu {
    void initArray(int &size, int &maxNum) {
        std::cout << "# - 1차원 배열 리스트에 오신 것을 환영합니다!!" << std::endl;
        std::cout << "배열 최대 크기 입력 : ";
        std::cin >> size;
        std::cout << "랜덤 최대 범위 입력 : ";
        std::cin >> maxNum;
    }

    void printArray(const arr::Array &newArray) {
        std::cout << "# - 현재 배열에 저장된 갯수는 " << newArray.getCount() << "이며, 최대 저장 가능한 갯수는 " << newArray.getSize() << "입니다." << std::endl;
        std::cout << "현재 저장된 배열들 : "; 

        for(int i = 0; i < newArray.getCount(); i++)
            std::cout << newArray.getArrNum(i) << ' ';

        std::cout << std::endl;

        return;
    }

    bool menuList(arr::Array &newArray) {
    int menu, target, value;

    std::cout << "####################" << std::endl;
    std::cout << "# - 1차원 배열 리스트 메인 메뉴" << std::endl;
    printArray(newArray);
    std::cout << "1. 삽입: 배열의 특정 위치에 요소를 삽입합니다." << std::endl;
    std::cout << "2. 삭제: 배열에서 요소를 삭제하고, 나머지 요소들을 이동시킵니다." << std::endl;
    std::cout << "3. 검색: 주어진 값이 배열에 있는지 확인하고, 그 위치를 반환합니다." << std::endl;
    std::cout << "4. 업데이트: 배열의 특정 위치에 있는 값을 새로운 값으로 변경합니다." << std::endl;
    std::cout << "9. 프로그램 종료" << std::endl;

    std::cin >> menu;

    if((menu >= 1 && menu <= 9) == false) {
        std::cout << "1부터 9사이의 숫자만 입력해 주세요!!";
        return true;
    }

    switch(menu) {
        case 1:
            std::cout << "값을 삽입할 위치 : ";
            std::cin >> target;
            std::cout << target << "번 쪽에 삽입할 값 : ";
            std::cin >> value;
            newArray.insertArray(target, value);
            break;
        case 2:
            std::cout << "지워질 값이 있는 위치 : ";
            std::cin >> target;
            newArray.deleteArray(target);
            break;
        case 3:
            std::cout << "검색할 값 : ";
            std::cin >> value;
            if(newArray.searchTarget(value) >= 0) { std::cout << newArray.searchTarget(value) << "번째에 위치합니다!!" << std::endl; }
            else { std::cout << "존재하지 않는 값 입니다!!" << std::endl; }
            break;
        case 4:
            std::cout << "바꿀 값이 있는 위치 : ";
            std::cin >> target;
            std::cout << target << "번 쪽에 새롭게 입력할 값 : ";
            std::cin >> value;
            newArray.updateTarget(target, value);
            break;
        case 9:
            return false;
        default:
            std::cout << "잘못된 입력입니다." << std::endl;
    }
    return true;
}
}