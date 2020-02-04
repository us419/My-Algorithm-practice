# Depth First Search

### 기본 그래프 개념
* 인접리스트 (adjacent list)
  * edge(u,v)의 존재를 확인하려면 adj[u]를 처음부터 읽어가면서 확인해야함 (리스트니까)
  * V개의 연결리스트에 실제 edge수만큼 원소가 들어있으므로 O(V+E)의 공간을 사용
* 인접행렬 (adjacent matrix)
  * edge(u,v)의 유무를 배열로 한번에 접근 가능
  * 무조건 O(V^2)의 공간을 사용
* 희소 그래프(sparse graph)의 경우 인접리스트, 밀집 그래프(dense graph)의 경우 인접행렬을 사용하는 것이 일반적으로 유리
----------------------------------------    
### DFS
    
#### 시간 복잡도
* 인접리스트의 경우 O(V+E) (모든 vertex에 대해 dfs() 호출, dfs() 호출되면 모든 edge 확인)
* 인접행렬의 경우 O(V^2) (모든 vertex에 대해 dfs() 호출, dfs() 호출되면 모든 vertex 돌면서 edge 확인)

#### 사용 예시 1 : 위상정렬 (Topological sort)
* DAG(cycle 없는 directed graph)의 vertex를 정렬하는 것
* dfs 호출 후 순서를 반대로 뒤집으면 topological sort가 됨
* cycle이 있는 경우는 backword edge가 있으므로 이거 확인하면 됨

#### 사용 예시 2 : 오일러 서킷 (Euler circuit)
* 존재 조건
  * undirected graph : 모든 vertex의 degree가 짝수
  * directed graph : 모든 vertex의 indegree = outdegree
* 오일러 트레일 (Euler trail)
  * 점 a에서 시작해 점 b로 끝나는 trail -> edge(a,b) 추가하고 Euler circuit 찾은 후 edge(a,b) 끊으면 됨
* 해밀턴 경로 (Hamilton path)
  * 해밀턴 경로 찾는 유일한 방법은 조합 탐색 -> worst case : n!
  * wordchain.cpp에서는 각 단어를 vertex가 아닌 edge로 표현해서 Euler circuit 문제로 바꿈

#### 사용 예시 3 : 절단점 찾기 (Cut vertex)
* dfs()를 수행해 DFS spanning tree를 만듬
* 자손들중에서 선조로 가는 backword edge가 있다면 절단점 아님
* root인 경우도 child가 2개 이상이여야 절단점이다 (주의)

#### 사용 예시 4 : 최소지배집합 찾기 (Minimum dominating set)
* 임의의 시작점에서 dfs() 수행 -> DFS spanning tree는 원래 그래프 구조를 가지면서 트리구조를 갖음 (루트없는 트리)
* 알고리즘
  * 잎 노드는 선택 안함
  * 이 외의 노드에 대해 트리의 맨 밑에서부터 올라오면서
    * child 중에서 지배당하지 않는 노드가 하나라도 있으면 현재 노드 선택
    * otherwise, 현재 노드 선택 안함

#### 사용 예시 5 : SCC
* SAT 문제는 NP-complete 문제지만 2-SAT의 경우 그래프로 바꾸면 SCC로 다항시간 내에 풀수 있음
