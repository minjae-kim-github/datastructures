/*

스택 헤더
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __STACK_HEADER__
#define __STACK_HEADER__

namespace Back { // 뒤에서 기능 구현을 위해 작동하는 클래스들
    class Data { // 각 노드당 저장될 데이터들
    private:
        std::string name;
        int age;
        std::string phoneNum;
    public:
        // ("이름", 나이, "전화번호") 순으로 인자를 전달받아 초기화
        Data(const std::string rname, const int rage, const std::string rphoneNum);
        void printData() const; // 노드에 저장된 데이터들을 출력해주는 함수
    };

    class Node {
    private:
        Data * data; // 데이터를 저장하기 위해 선언
        Node * next;
    public:
        // ("이름", 나이, "전화번호") 순으로 인자를 전달받아 data 객체 생성 및 초기화
        Node(const std::string rname, const int rage, const std::string rphoneNum);
        Data * getData() const; // data의 printData() 함수에 접근하기 위해 선언
        Node * getNext() const; // next 주소에 접근하기 위해 선언
        Node * setNext(Node * rnext); // next를 설정하기 위해 선언
        ~Node(); // data 객체 삭제하는 소멸자
    };

    class Stack {
    private:
        Node * head;
    public:
        Stack(); // 생성자
        bool pop(); // 저장된 노드를 꺼내는 함수, 만일 스택 내 저장된 노드가 없을 경우 false 반환
        // ("이름", 나이, "전화번호") 순으로 인자를 전달받아 객체 노드를 만들어서 스택에 집어넣는 함수
        void push(const std::string rname, const int rage, const std::string rphoneNum);
    };
}

#endif