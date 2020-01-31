# Implementation of tree

* 기본적인 트리구현
* fortress.cpp 문제 풀면서 실수 한 것
  * for문 돌리면서 for문에 쓰이는 변수를 바꾸지 말 것 (ex : iterator로 돌리면서 list.erase(iter) 하지 말것)
  * 꼭 바꿔야 겠다면 temp = it; temp++; list.erase(it); it = temp <- 이런식으로 바꾸자
