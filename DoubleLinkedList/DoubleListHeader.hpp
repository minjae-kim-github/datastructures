/*

더블 연결 리스트 헤더
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __DOUBLE_LIST_HEADER__
#define __DOUBLE_LIST_HEADER__

namespace Back { // 뒤에서 기능을 구현하는 클래스들
    class Data { // 각 노드 당 저장될 데이터를 저장하는 클래스
    private:
        std::string name;
        int age;
        std::string phoneNum;
    public:
        // ("이름", 나이, "전화번호") 순으로 인자를 전달받아 초기화
        Data(const std::string rname, const int rage, std::string rphoneNum);
        void printData(); // 노드에 저장된 데이터들을 출력하기 위해 선언한 함수
    };

    class Node { // 각 노드당 생성되는 정보들
    private:
        Data * data;
        Node * next;
        Node * before;
    public:
        // ("이름", 나이, "전화번호") 순으로 인자를 전달받아 Data 클래스와 Node 클래스 초기화
        Node(const std::string rname, const int rage, std::string rphoneNum);
        Data * getData(); // data 리턴해주는 함수
        Node * getNext(); // next 리턴해주는 함수
        Node * setNext(Node * rnext); // next 설정해주는 함수
        Node * getBefore(); // before 리턴해주는 함수
        Node * setBefore(Node * rbefore); // before 설정해주는 함수
    };

    class DoubleList {
    private:
        Node * head;
        Node * temp;
        int existCount; // 노드가 존재하는 수
    public:
        DoubleList(); // 초기화
        // ("이름", 나이, "전화번호") 순으로 인자를 전달받아 Node 객체를 새로 만들고, 이를 연결시켜주는 함수
        void Create(const std::string rname, const int rage, std::string rphoneNum);
        void Delete(const int target); // target에 위치한 노드를 삭제해주는 함수 (노드는 오른쪽 기준으로 1부터 시작한다.)
        void printAll(); // 존재하는 모든 노드들의 정보를 모두 출력하는 함수
    };
}

#endif