# Linear Data Structure
### Array
* 원소들이 인접한 메모리에 저장
* 임의의 원소 참조하는데 편리 / 원소 삽입, 삭제에 O(n) (끝 원소 말고)
* 고정된 크기를 할당함 (동적 배열의 경우 capacity를 통해 단점을 어느정도 보완)
* Static Array vs Dynamic Array
+ C++ STL에서 <array> vs <vector>
+ vector의 경우 append, resize 등의 연산을 지원
+ capacity를 통해 append할때마다 배열 전체를 복사하지 않아도 됨

        
### List
* 원소들이 포인터로 서로 연결됨
* C++ STL <list> (Double linked list)
* 원소 삽입, 삭제에 편리 / 임의의 원소 참조하는데 O(n)

      
### Dynamic array vs Linked list
|  <center>작업/center> |  <center>Dynamic Array/center> |  <center>Linked List/center> |
|:--------|:--------:|:--------:|
|**이전 원소/다음 원소 찾기** | <center>O(1)</center> |*O(1)*|
|**맨 뒤에 원소 추가/삭제하기** | <center>O(1)</center> |*O(1)* |
|**맨 뒤 이외의 위치에 원소 추가/삭제하기** | <center>O(n)</center> |*O(1)* |
|**임의의 위치의 원소 찾기** | <center>O(1)</center> |*O(n)* |
|**크기 구하기** | <center>O(1)</center> |*O(n) (C++ STL에서만)* |
