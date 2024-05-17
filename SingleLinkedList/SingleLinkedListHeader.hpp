/*

단일 연결 리스트 헤더
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

#include <string>

#ifndef __SINGLE_LINKED_LIST_HEADER__
#define __SINGLE_LINKED_LIST_HEADER__

namespace Back { // 뒤에서 구동되는 기능들
class Data {
private:
// 아래에 각 노드마다 저장할 데이터들을 선언 (아래는 예시)
    std::string name;
    int age;
public:
    Data(); // 초기화 함수
    void insertName(const std::string& rname); // 이름을 저장하는 함수
    void insertAge(const int rage); // 나이를 저장하는 함수
    std::string getName() const; // 저장된 이름을 반환받는 함수
    int getAge() const; // 저장된 나이를 반환받는 함수
};

class Node {
private:
    Data * data; // 각 노드마다 Data 라는 클래스 정보를 저장하기 위함
    Node * next; // 다음 노드로 연결할 수 있도록 작성
public:
    Node(); // 초기화 함수
    void insertData(const std::string& rname, const int rage); // 데이터 입력 함수
    void SetNext(Node * nextNode); // 다음 노드로 연결시켜주는 함수
    Node * GetNext(); // 다음 노드 정보를 받아오는 함수
    Data * getData(); // 데이터 받아오는 함수
};

class LinkedList {
private:
    Node * head;
    Node * tail;
    Node * cur;
    int existCount; // 현재 존재하는 노드의 수를 저장하기 위해 선언
public:
    LinkedList();

    void Create(const std::string& rname, const int rage); // 노드를 생성하는 기능
    void Print(const int target); // 특정 번호에 저장된 노드의 정보를 출력하는 기능
    void PrintAll(); // 저장된 노드들의 정보를 모두 출력하는 기능
    void Delete(const int target); // 특정 번호에 저장된 노드를 삭제하는 기능
    void DeleteAll(); // 모든 노드를 메모리에서 삭제시키는 기능
};
}

#endif