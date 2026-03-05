# Comparison of Search Algorithms using the N-Queens Problem

The **N-Queens problem** is a classical search problem in Artificial Intelligence where the objective is to place N queens on an N × N chessboard such that no two queens attack each other. Various search strategies can be applied to explore the state space and find a valid solution. The following is a comparison of several uninformed search algorithms used to solve the problem.

## 1. Breadth First Search (BFS)
Breadth First Search explores the search tree level by level. It expands all nodes at the current depth before moving to the next level.

**Characteristics**
- Uses a queue (FIFO data structure).
- Guarantees finding the shallowest solution.
- Requires large memory because it stores all nodes at each level.

**Advantages**
- Complete if the branching factor is finite.
- Finds the optimal solution when all step costs are equal.

**Disadvantages**
- Memory consumption grows rapidly for large problems like N-Queens.

---

## 2. Depth First Search (DFS)
Depth First Search explores a branch of the search tree as deeply as possible before backtracking.

**Characteristics**
- Uses a stack (LIFO data structure).
- Goes deep into one branch before exploring others.

**Advantages**
- Requires less memory than BFS.
- Simple to implement.

**Disadvantages**
- May get stuck in deep branches.
- Does not guarantee the optimal solution.

---

## 3. Uniform Cost Search (UCS)
Uniform Cost Search expands the node with the lowest path cost first.

**Characteristics**
- Uses a priority queue.
- Considers path cost when selecting the next node.

**Advantages**
- Guarantees the optimal solution when costs are positive.
- Works well when step costs differ.

**Disadvantages**
- Slower than BFS when all step costs are equal.
- Requires more memory due to storing many nodes.

---

## 4. Depth Limited Search (DLS)
Depth Limited Search is a modified version of DFS where the search depth is limited to a fixed value.

**Characteristics**
- Uses DFS strategy with a depth limit.
- Prevents infinite search in very deep trees.

**Advantages**
- Controls excessive depth exploration.
- Uses less memory.

**Disadvantages**
- May fail to find the solution if the depth limit is too small.

---

## 5. Bidirectional Search
Bidirectional Search runs two searches simultaneously: one from the start state and the other from the goal state.

**Characteristics**
- Searches forward and backward until both meet.
- Reduces the effective search depth.

**Advantages**
- Much faster than BFS in many cases.
- Reduces search space significantly.

**Disadvantages**
- Requires knowledge of the goal state.
- More complex to implement.

---

## 6. Iterative Deepening Depth First Search (IDDFS)
IDDFS combines the advantages of BFS and DFS by repeatedly performing DFS with increasing depth limits.

**Characteristics**
- Performs depth-limited searches with gradually increasing limits.
- Uses DFS internally.

**Advantages**
- Requires less memory like DFS.
- Finds optimal solutions like BFS when step costs are equal.

**Disadvantages**
- Some nodes are expanded multiple times.

---

# Overall Comparison

| Algorithm | Data Structure Used | Completeness | Optimality | Memory Usage | Main Advantage | Main Disadvantage |
|-----------|--------------------|--------------|------------|--------------|---------------|------------------|
| BFS | Queue | Complete | Optimal (equal costs) | Very High | Finds shallowest solution | High memory usage |
| DFS | Stack | Not always complete | Not optimal | Low | Memory efficient | May get stuck in deep paths |
| UCS | Priority Queue | Complete | Optimal | High | Considers path cost | Slower if costs equal |
| DLS | Stack | Not always complete | Not optimal | Low | Prevents infinite depth | May miss solution |
| Bidirectional | Queue/Two searches | Complete | Optimal (equal costs) | Moderate | Reduces search time | Harder to implement |
| IDDFS | Stack | Complete | Optimal (equal costs) | Low | Combines BFS and DFS benefits | Repeats node expansions |

## Conclusion
Each search algorithm has its own strengths and weaknesses. BFS and UCS guarantee optimal solutions but require high memory. DFS and DLS use less memory but may fail to find optimal solutions. Bidirectional search reduces the search space significantly, while IDDFS provides a balance between memory efficiency and completeness. The choice of algorithm depends on the problem size, memory constraints, and the need for optimal solutions.
