/*

1차원 배열 리스트 헤더 파일
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

namespace arr {
    class Array {
    private:
        int *num; // GPT가 수정해준 동적 배열
        int count;
        int size;
    public:
        Array(int size, int maxNum); // 생성자 호출

        // 기능들을 구현하기 위하여 보조해주는 함수들
        bool isArrEmpty() const; // 배열이 비어 있는지 확인하는 함수
        bool isArrFull() const; // 배열이 꽉 찼는지 확인하는 함수
        int getCount() const; // 카운트 값을 받아서 넘겨주는 함수
        int getSize() const; // 사이즈 값을 받아서 넘겨주는 함수
        int getArrNum(int target) const; // 배열의 타켓에 저장된 값을 넘겨주는 함수

        // 기능들을 구현해둔 함수들
        void insertArray(int target, int value); // 배열에 숫자 삽입하는 함수
        void deleteArray(int target); // 타겟을 찾아서 배열에서 지워버리는 함수
        int searchTarget(int value); // 배열에서 타겟을 찾은 뒤, 저장된 위치를 반환하는 함수
        void updateTarget(int target, int value); // 특정 위치에 저장된 값을 지정한 값으로 바꾸는 함수

        ~Array(); // 소멸자 호출
    };
}

namespace menu {
    void initArray(int &size, int &maxNum);
    void printArray(const arr::Array &newArray); // 현재 배열에 저장된 값들을 출력해주는 코드
    bool menuList(arr::Array &newArray); // GPT가 수정해준 코드
}