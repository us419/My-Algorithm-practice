# Queue & Stack & Dequeue
### Queue
* C++ STL queue
* FIFO
        
### Stack
* C++ STL stack
* LIFO
    
### Dequeue
* C++ STL deque
* 양쪽 끝에서 자료들을 넣고 뺄 수 있음

### 구현
* Linked List 사용시 편함
* Dynamic Array 사용시
  * Stack은 바로 가능
  * Queue와 Dequeue의 경우 원소의 위치를 head와 tail에 유지
  * 버려지는 공간이 많으므로 circular buffer 사용
  
---
### ites.cpp
* 이 문제를 보면 입력의 크기가 매우 크다 (1 <= N <= 50,000,000)
* 입력을 자료구조에 저장해놓는 것이 불가능
#### 온라인 알고리즘
* 전체 입력이 한꺼번에 주어지지 않아도 계산을 시작할 수 있는 알고리즘
* ex : insertion sort
#### 오프라인 알고리즘
* 입력 전체를 이미 가지고 있다고 가정하고 동작하는 알고리즘
* ex : selection sort
    
### 스위핑 알고리즘 (나중에 다시 와서 풀어볼 것)
