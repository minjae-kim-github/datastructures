/*

원형 연결 리스트 헤더
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __CIRCLE_LIST_HEADER__
#define __CIRCLE_LIST_HEADER__

namespace Back { // 뒤에서 기능 구현을 위해 구현되는 코드들
    class Data { // 개별 노드마다 저장될 데이터들을 보관하는 클래스
    private:
        std::string name; // 이름
        int age; // 나이
        std::string phoneNum; // 전화번호

    public:
        Data(); // 만일 인자로 아무것도 전달받지 못했을 때, 초기화 ("", 0, 0으로 초기화 됨)
        // 인자로 이름, 나이, 전화번호를 전달받았을 때, 해당 정보 기반으로 초기화
        Data(const std::string rname, const int rage, std::string rphoneNum);
        void printData() const; // Data 클래스에 저장된 정보(이름, 나이, 전화번호)를 출력
    };

    class Node {
    private:
        Data * data; // 노드에 저장될 데이터, 위에 Data 클래스를 수정하여 저장될 정보들을 추가, 삭제, 수정 가능
        Node * next; // 노드에서 다음 노드로 연결하기 위해 작성
    public:
        Node(); // 만일 인자로 아무것도 전달받지 못했을 때, 초기화
        // 인자로 이름, 나이, 전화번호를 전달받았을 때, 해당 정보 기반으로 초기화
        Node(const std::string rname, const int rage, std::string rphoneNum);
        void setNext(Node * nextNode); // 다음 노드로 연결시켜주는 함수
        Data * getData(); // 데이터 받아오는 함수
        Node * getNext(); // 노드의 next을 리턴해주는 함수
        ~Node(); // 소멸자
    };

    class CircleList {
    private:
        Node * tail;
        Node * temp;
        int existCount;
    public:
        CircleList(); // 생성자

        void Create(const std::string rname, const int rage, std::string rphoneNum); // 노드를 생성하는 기능
        void PrintAll(); // 저장된 노드들의 정보를 모두 출력하는 기능
        void Delete(const int target); // 타겟에 있는 노드를 삭제하는 기능
    };
}

#endif