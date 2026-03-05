# Comparison of Search Algorithms (Using N-Queens Problem)

In the N-Queens problem, different search algorithms can be used to explore possible board configurations and find a valid arrangement of queens. Each algorithm searches the state space in a different way, so their performance also differs.

## Breadth First Search (BFS)
Breadth First Search explores the search tree level by level. It first checks all possible states at depth 1, then depth 2, and so on.

BFS can always find a solution if one exists, but it uses a lot of memory because it stores many states at the same time. For problems like N-Queens where the number of states is large, BFS can become slow and memory intensive.

## Depth First Search (DFS)
Depth First Search explores one branch completely before moving to another branch. It goes deep into the search tree and backtracks when it reaches a dead end.

DFS uses less memory compared to BFS, but it does not guarantee the shortest or best solution. Sometimes it may spend a lot of time exploring a wrong path.

## Uniform Cost Search (UCS)
Uniform Cost Search expands the node that has the lowest path cost. It uses a priority queue to decide which node to explore next.

If the costs of all steps are the same, UCS behaves similarly to BFS. It guarantees the optimal solution, but it can be slower because it keeps checking the cost of each path.

## Depth Limited Search (DLS)
Depth Limited Search is similar to DFS, but it limits how deep the search can go. This helps avoid going too deep in the search tree.

However, if the depth limit is too small, the algorithm may not find the solution even if one exists.

## Bidirectional Search
Bidirectional Search works by searching from both the start state and the goal state at the same time. The search stops when the two searches meet.

This method can reduce the search time because the search space becomes smaller. However, it is harder to implement and requires knowledge of the goal state.

## Iterative Deepening DFS (IDDFS)
Iterative Deepening DFS is a combination of BFS and DFS. It runs DFS multiple times with increasing depth limits.

This approach uses less memory like DFS but still ensures that the shallowest solution is found like BFS. The only drawback is that some nodes may be explored more than once.

## Overall Comparison
BFS and UCS are reliable because they can always find a solution when one exists, but they require more memory. DFS and DLS are more memory efficient but may miss the best or shallowest solution. Bidirectional search can reduce the search effort if the goal state is known. IDDFS tries to balance the advantages of BFS and DFS by using less memory while still being able to find shallow solutions.

