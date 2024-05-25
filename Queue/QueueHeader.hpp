/*

큐 헤더
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

namespace Back { // 뒤에서 구동되는 함수들
    class Data { // 각 노드당 저장될 데이터들
    private:
        std::string name;
        int age;
        std::string phoneNum;
    public:
        // ("이름", 나이, "전화번호") 정보를 기반으로 Data 초기화
        Data(const std::string rname, const int rage, const std::string rphoneNum);
        void printData() const; // 노드에 저장된 데이터를 출력
    };

    class Node {
    private:
        Data * data;
        Node * next;
    public:
        // ("이름", 나이, "전화번호") 정보를 기반으로 Data 객체 생성 및 Node 초기화
        Node(const std::string rname, const int rage, const std::string rphoneNum);
        Data * getData(); // data에 접근하기 위해서 데이터를 리턴해주는 함수 선언
        Node * getNext(); // next에 접근하기 위해서 next를 리턴해주는 함수 선언
        Node * setNext(Node * rnext); // -> next = rnext와 동일하게 기능하는 함수 선언
        ~Node(); // 소멸자
    };

    class Queue {
    private:
        Node * front;
        Node * rear;
    public:
        Queue(); // Queue 초기화
        // ("이름", 나이, "전화번호") 정보를 기반으로 노드를 생성한 후, 기존 노드와 연결
        void Enqueue(const std::string rname, const int rage, const std::string rphoneNum);
        /* 제일 먼저 저장된 노드의 데이터를 출력한 뒤, 삭제 (즉, 선입선출),
        만일 기존에 저장된 노드가 없을 경우 false 반환, 만일 기존에 저장된 노드의 데이터를 출력하고 삭제 성공할 시 true 반환 */
        bool Dequeue();
    };
}