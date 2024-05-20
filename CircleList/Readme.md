C++로 구현해본 자료구조 원형 연결 리스트 파일입니다.   
CircleList.exe 파일을 다운로드 하시면 실행이 가능하며, 소스 코드는 CircleListMain.cpp, CircleListHeader.hpp, CircleListFunc.cpp 총 3개입니다.   
작동 원리는 추후 블로그에 게시 예정이며, 게시 후 링크 올릴 예정입니다.   
===== ADT =====   
1. Create(rname, rage, rphoneNum);   
노드를 생성하는 기능으로, 순차대로 인자에 ("이름", 나이, "전화번호") 넣어주시면 됩니다.   
2. PrintAll();
모든 노드를 순회하며 출력하는 기능입니다. 인자로 전달해야 할 것은 없습니다.
3. Delete(target);
삭제하고 싶은 노드가 위치한 곳을 인자로 전달하시면 됩니다. 원의 제일 왼쪽을 기준으로 노드는 1번부터 시작합니다.
