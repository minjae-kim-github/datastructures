/*

1���� �迭 ����Ʈ ��� ����
Blog: https://velog.io/@minjaek
Github: https://github.com/minjae-kim-github

*/

namespace arr {
    class Array {
    private:
        int *num; // GPT�� �������� ���� �迭
        int count;
        int size;
    public:
        Array(int size, int maxNum); // ������ ȣ��

        // ��ɵ��� �����ϱ� ���Ͽ� �������ִ� �Լ���
        bool isArrEmpty() const; // �迭�� ��� �ִ��� Ȯ���ϴ� �Լ�
        bool isArrFull() const; // �迭�� �� á���� Ȯ���ϴ� �Լ�
        int getCount() const; // ī��Ʈ ���� �޾Ƽ� �Ѱ��ִ� �Լ�
        int getSize() const; // ������ ���� �޾Ƽ� �Ѱ��ִ� �Լ�
        int getArrNum(int target) const; // �迭�� Ÿ�Ͽ� ����� ���� �Ѱ��ִ� �Լ�

        // ��ɵ��� �����ص� �Լ���
        void insertArray(int target, int value); // �迭�� ���� �����ϴ� �Լ�
        void deleteArray(int target); // Ÿ���� ã�Ƽ� �迭���� ���������� �Լ�
        int searchTarget(int value); // �迭���� Ÿ���� ã�� ��, ����� ��ġ�� ��ȯ�ϴ� �Լ�
        void updateTarget(int target, int value); // Ư�� ��ġ�� ����� ���� ������ ������ �ٲٴ� �Լ�

        ~Array(); // �Ҹ��� ȣ��
    };
}

namespace menu {
    void initArray(int &size, int &maxNum);
    void printArray(const arr::Array &newArray); // ���� �迭�� ����� ������ ������ִ� �ڵ�
    bool menuList(arr::Array &newArray); // GPT�� �������� �ڵ�
}