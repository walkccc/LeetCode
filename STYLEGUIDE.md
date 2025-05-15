# Style Guide

> This document has been reviewed and discussed with
> [@hsins](https://github.com/hsins).
>
> For further reading, please see the definition of
> [Convention over configuration in Wikipedia](https://en.wikipedia.org/wiki/Convention_over_configuration).

## Introduction

This style guide is specifically for LeetCode and is based on Google style
guides with adjustments specific to LeetCode. It aims to maintain consistency
across different programming languages while adhering to LeetCode's conventions.

## Language-Specific Guidelines

### General Rules

1. Use `lowerCamelCase` for both functions and variables. While this may deviate
   from the rules laid out in the
   [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#General_Naming_Rules)
   and
   [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html),
   it is done to maintain consistency with the LeetCode OJ system, which employs
   `lowerCamelCase` for over 99% of the time. Remember, the most important thing
   is to be consistent at all times.
1. Import statements and brackets `()` may be omitted for better viewing
   experience on mobile devices, but they should be retained in real-world
   coding situations for clarity and maintainability.

### C++

1. The code is only for demonstration and cannot be compiled.
1. `#include` statements are omitted in code snippets for brevity.
1. Understanding the difference between `size_t` and `int` is crucial when
   traversing arrays in practical applications, as it can affect the outcome.
1. Qualifying with `std::` prefix when accessing standard libraries is
   recommended in real-world, as it clearly indicates the source of the
   identifier being used and avoid name conflicts.

### Java

1. The code is only for demonstration and cannot be compiled.
1. `import` statements are omitted in code snippets for brevity.

### Python

1. Private functions are prefixed with `_`, which may seem tedious. However, in
   the real world, we use tools like [Mypy](https://github.com/python/mypy),
   [Pytype](https://github.com/google/pytype), and
   [Pyre](https://github.com/facebook/pyre-check) for static type checking.
1. We pass the argument `--indent-size=2` to
   [autopep8](https://pypi.org/project/autopep8/) for a better viewing
   experience on mobile devices.
1. `import` statements are omitted in code snippets for brevity.
1. Variables like `next` and `hash` are reserved keywords. For consistency with
   C++ and Java naming conventions, we'll use them. However, in practice, using
   reserved keywords as variable names can cause confusion and issues. It's
   better to choose names that avoid such conflicts.

### SQL

1. The naming of LeetCode is quite a mess and inconsistently uses plurals and
   singulars together. I'll use my best judgment to name tables in
   `UpperCamelCase` in the plural form and fields in `lower_snake_case`.
1. Proper indentation will be taken care of and treated seriously.
1. No puzzling table abbreviation.

## Naming Conventions

- **Class:** `UpperCamelCase`
- **Function:** `lowerCamelCase`
- **Variable:** `lowerCamelCase`
- **Constant:** `kUpperCamelCase`

### Examples

=== "C++"

    ```cpp
    // Class
    class MyClass { ... }

    // Function
    void myFunction(int param) { ... }

    // Variable
    int myVariable = 0;

    // Constant
    constexpr int kMod = 1'000'000'007;
    ```

=== "Java"

    ```java
    // Class
    class MyClass { ... }

    // Function
    void myFunction(int param) { ... }

    // Variable
    int myVariable = 0;

    // Constant
    final int kMod = 1_000_000_007;
    ```

=== "Python"

    ```python
    # Class
    class MyClass:
      pass

    # Function
    def myFunction(param: int) -> None:
      pass

    # Variable
    myVariable = 0

    # Constant
    kMod = 1_000_000_007
    ```

## Code Structure

### Rules

- Declare the variables in the proper scope as slow as possible.
- Declare the constants as soon as possible.
- Declare `ans` as soon as possible.
- No blank lines between variables initialization.
- Blank one single line between each main section.
- If the last statement is not a paragraph (`for` loop most of the case), then
  no blank lines between it and the `return` statement.
- Since LeetCode is just an online judge system rather than a big project, we
  don't scatter all variables in different sections. However, we still sort the
  variables based on the time we first use each of them.

### Template

=== "C++"

    ```cpp
    class Solution {
     public:
      // public functions
      int mainFunction() {
        // (sec 0) boundary conditions

        // (sec 1) variables initialization
        //   (sec 10) constexpr/const (size/length)
        //   (sec 11) ans
        //   (sec 12) declaration & operation
        //   (sec 13) purely declaration

        // (sec 2) kernels

        // (sec 3) modify original initial variables

        // (sec 4) kernels

        // (sec n) return
      }

    private:
      // private variables
      static constexpr int kMod = 1'000'000'007;

      // private functions
      void myHelper(int param) { ... }

      string myAnotherHelper(const vector<string>& param) { ... }
    };
    ```

=== "Java"

    ```java
    class Solution {
      // public functions
      public int mainFunction() {
        // (sec 0) boundary conditions

        // (sec 1) variables initialization
        //   (sec 10) final (size/length)
        //   (sec 11) ans
        //   (sec 12) declaration & operation
        //   (sec 13) purely declaration

        // (sec 2) kernels

        // (sec 3) modify original initial variables

        // (sec 4) kernels

        // (sec n) return
      }

      // private variables
      private static final int kMod = 1_000_000_007;

      // private functions
      private void myHelper(int param) { ... }

      private String myAnotherHelper(List<String> param) { ... }
    }
    ```

=== "Python"

    ```python
    class Solution:
      def __init__(self):
        # private variables
        self.kMod = 1_000_000_007

      # public functions
      def mainFunction(self) -> int:
        pass
        # (sec 0) boundary conditions

        # (sec 1) variables initialization
        #   (sec 10)
        #   (sec 11) ans
        #   (sec 12) declaration & operation
        #   (sec 13) purely declaration

        # (sec 2) kernels

        # (sec 3) modify original initial variables

        # (sec 4) kernels

        # (sec n) return

      # private functions
      def _myHelper(self, param: int) -> None:
        pass

      def _myAnotherHelper(self, param: List[str]) -> str:
        pass
    ```

## Data Structures and Algorithms

### Two Pointers / Sliding Windows

1. Always prefer to _one_ character to represent index variables.
1. Use `i`, `j`, `k` in the loop, in that order.

=== "C++"

    ```cpp
    int i = 0;
    for (const int num : nums) { ... }
    ```

=== "Java"

    ```java
    int i = 0;
    for (final int num : nums) { ... }
    ```

=== "Python"

    ```python
    i = 0
    for num in nums:
      pass
    ```

---

=== "C++"

    ```cpp
    for (int i = 0, j = 0; i < n; ++i) { ... }
    ```

=== "Java"

    ```java
    for (int i = 0, j = 0; i < n; ++i) { ... }
    ```

=== "Python"

    ```python
    j = 0
    for i in range(n):
      pass
    ```

---

=== "C++"

    ```cpp
    int k = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j) { ... }
    ```

=== "Java"

    ```java
    int k = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j) { ... }
    ```

=== "Python"

    ```python
    k = 0
    for i in range(n):
      for j in range(i, n):
        pass
    ```

### Union Find

> Demo the Path Compression and Union by Rank version, where the time complexity
> of `unionByRank()` and `find` is $O(\alpha(n)) = O(\log^\* n)$.

=== "C++"

    ```cpp
    class UnionFind {
     public:
      UnionFind(int n) : count(n), id(n), rank(n) {
        iota(begin(id), end(id), 0);
      }

      void unionByRank(int u, int v) {
        const int i = find(u);
        const int j = find(v);
        if (i == j)
          return;
        if (rank[i] < rank[j]) {
          id[i] = id[j];
        } else if (rank[i] > rank[j]) {
          id[j] = id[i];
        } else {
          id[i] = id[j];
          ++rank[j];
        }
        --count;
      }

      int getCount() const {
        return count;
      }

    private:
      int count;
      vector<int> id;
      vector<int> rank;

      int find(int u) {
        return id[u] == u ? u : id[u] = find(id[u]);
      }
    };
    ```

=== "Java"

    ```java
    class UnionFind {
      public UnionFind(int n) {
        count = n;
        id = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i)
          id[i] = i;
      }

      public void unionByRank(int u, int v) {
        final int i = find(u);
        final int j = find(v);
        if (i == j)
          return;
        if (rank[i] < rank[j]) {
          id[i] = j;
        } else if (rank[i] > rank[j]) {
          id[j] = i;
        } else {
          id[i] = j;
          ++rank[j];
        }
        --count;
      }

      public int getCount() {
        return count;
      }

      private int count;
      private int[] id;
      private int[] rank;

      private int find(int u) {
        return id[u] == u ? u : (id[u] = find(id[u]));
      }
    }
    ```

=== "Python"

    ```python
    class UnionFind:
      def __init__(self, n: int):
        self.count = n
        self.id = list(range(n))
        self.rank = [0] * n

      def unionByRank(self, u: int, v: int) -> None:
        i = self._find(u)
        j = self._find(v)
        if i == j:
          return
        if self.rank[i] < self.rank[j]:
          self.id[i] = j
        elif self.rank[i] > self.rank[j]:
          self.id[j] = i
        else:
          self.id[i] = j
          self.rank[j] += 1
        self.count -= 1

      def getCount(self) -> int:
        return self.count

      def _find(self, u: int) -> int:
        if self.id[u] != u:
          self.id[u] = self._find(self.id[u])
        return self.id[u]
    ```

### Graph / Tree

1. If a graph has a clear tree structure, we name it with `tree`. Otherwise, we
   name it with `graph`.
1. Always use `(u, v)` to represent an edge regardless what is stated in the
   problem.

=== "C++"

    ```cpp
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    ```

=== "Java"

    ```java
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }
    ```

=== "Python"

    ```python
    graph = [[] for _ in range(n)]

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)
    ```

### Dijkstra

=== "C++"

    ```cpp
    int dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
      vector<int> dist(graph.size(), INT_MAX);

      dist[src] = 0;
      using P = pair<int, int>;  // (d, u)
      priority_queue<P, vector<P>, greater<>> minHeap;
      minHeap.emplace(dist[src], src);

      while (!minHeap.empty()) {
        const auto [d, u] = minHeap.top();
        minHeap.pop();
        if (d > dist[u])
          continue;
        for (const auto& [v, w] : graph[u])
          if (d + w < dist[v]) {
            dist[v] = d + w;
            minHeap.emplace(dist[v], v);
          }
      }

      const int maxDist = ranges::max(dist);
      return maxDist == INT_MAX ? -1 : maxDist;
    }
    ```

=== "Java"

    ```java
    private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src) {
      int[] dist = new int[graph.length];
      Arrays.fill(dist, Integer.MAX_VALUE);

      dist[src] = 0;
      Queue<Pair<Integer, Integer>> minHeap =
        new PriorityQueue<>(Comparator.comparing(Pair::getKey)) {
          { offer(new Pair<>(dist[src], src)); } // (d, u)
        };

      while (!minHeap.isEmpty()) {
        final int d = minHeap.peek().getKey();
        final int u = minHeap.poll().getValue();
        if (d > dist[u])
          continue;
        for (Pair<Integer, Integer> pair : graph[u]) {
          final int v = pair.getKey();
          final int w = pair.getValue();
          if (d + w < dist[v]) {
            dist[v] = d + w;
            minHeap.offer(new Pair<>(dist[v], v));
          }
        }
      }

      final int maxDist = Arrays.stream(dist).max().getAsInt();
      return maxDist == Integer.MAX_VALUE ? -1 : maxDist;
    }
    ```

=== "Python"

    ```python
    def _dijkstra(self, graph: list[list[tuple[int, int]]], src: int) -> int:
      dist = [math.inf] * len(graph)

      dist[src] = 0
      minHeap = [(dist[src], src)]  # (d, u)

      while minHeap:
        d, u = heapq.heappop(minHeap)
        if d > dist[u]:
          continue
        for v, w in graph[u]:
          if d + w < dist[v]:
            dist[v] = d + w
            heapq.heappush(minHeap, (dist[v], v))

      maxDist = max(dist)
      return maxDist if maxDist != math.inf else -1
    ```

### Binary Search

1. Always prefer to _one_ character to represent index variables.
1. Always prefer to use `[l, r)` pattern.

=== "C++"

    ```cpp
    int l = 1;
    int r = nums.size();

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (f(m))
        l = m + 1;  // new range [m + 1, r)
      else
        r = m;  // new range [l, m)
    }

    return l;
    ```

=== "Java"

    ```java
    int l = 1;
    int r = nums.length;

    while (l < r) {
      final int m = l + (r - l) / 2;
      if (f(m))
        l = m + 1;  // new range [m + 1, r)
      else
        r = m;  // new range [l, m)
    }

    return l;
    ```

=== "Python"

    ```python
    bisect.bisect_left(range(1, len(nums)), True,
                      key=lambda m: f(m)) + 1
    ```

## Common Patterns

### Built-in Types

=== "C++"

    ```cpp
    unordered_set<string> seen;
    unordered_map<char, int> count;
    vector<int> count;
    stack<char> stack;
    queue<TreeNode*> q;
    deque<TreeNode*> minQ;
    auto compare = [](const ListNode* a, const ListNode* b) {
      return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
    ```

=== "Java"

    ```java
    Set<String> seen = new HashSet<>();
    Map<Character, Integer> count = new HashMap<>();
    int[] count = new int[n];
    Deque<Character> stack = new ArrayDeque<>(); // Do not use `Stack`.
    Queue<Integer> q = new LinkedList<>();
    Deque<Integer> minQ = new ArrayDeque<>();
    Queue<ListNode> minHeap = new PriorityQueue<>(Comparator.comparing((ListNode a) -> a.val));
    ```

=== "Python"

    ```python
    seen = set()
    count = {}
    count = collections.defaultdict(int)
    count = collections.defaultdict(list)
    count = collections.Counter()
    minQ = collections.deque([root])
    stack = []
    minHeap = []
    ```

### Boundary Conditions

=== "C++"

    ```cpp
    // Linked-List
    if (l1 == nullptr && l2 == nullptr) { ... }
    if (l1 != nullptr || l2 != nullptr) { ... }

    // String
    if (s.empty()) { ... }
    if (s.length() <= 2) { ... }

    // Vector
    if (nums.size() <= 2) { ... }
    ```

=== "Java"

    ```java
    // Linked-List
    if (l1 == null && l2 == null) { ... }
    if (l1 != null || l2 != null) { ... }

    // String
    if (s.isEmpty()) { ... }
    if (s.length() <= 2) { ... }

    // Array
    if (nums.length <= 2) { ... }

    // List
    if (nums.size() <= 2) { ... }
    ```

=== "Python"

    ```python
    # Linked-List
    if not l1 and not l2:
      pass
    if l1 or l2:
      pass

    # String
    if not s:
      pass
    if len(s) <= 2:
      pass

    # List
    if len(nums) <= 2:
      pass
    ```

### ListNode

=== "C++"

    ```cpp
    // Allocate the memory on the stack instead of the heap.
    ListNode dummy(0);

    ListNode* curr = nullptr;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    ListNode* slow = nullptr;
    ListNode* fast = nullptr;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    ```

=== "Java"

    ```java
    ListNode dummy = new ListNode(0);

    ListNode curr = null;
    ListNode prev = null;
    ListNode next = null;

    ListNode slow = null;
    ListNode fast = null;

    ListNode head = null;
    ListNode tail = null;

    ListNode l1 = null;
    ListNode l2 = null;
    ```

=== "Python"

    ```python
    dummy = ListNode(0)

    curr = None
    prev = None
    next = None

    slow = None
    fast = None

    head = None
    tail = None

    l1 = None
    l2 = None
    ```

### 2D Vector/Array/List and 2 Strings

=== "C++"

    ```cpp
    // 2D Vector
    const int m = matrix.size();
    const int n = matrix[0].size();

    // If there're two strings.
    const int m = s1.length();
    const int n = s2.length();

    // If there's only a string.
    const int n = s.length();
    ```

=== "Java"

    ```java
    // 2D Array
    final int m = matrix.length;
    final int n = matrix[0].length;

    // If there're two strings.
    final int m = s1.length();
    final int n = s2.length();

    // If there's only a string.
    final int n = s.length();
    ```

=== "Python"

    ```python
    # 2D List
    m = len(matrix)
    n = len(matrix[0])

    # If there're two strings.
    m = len(s1)
    n = len(s2)

    # If there's only a string.
    n = len(s)
    ```

### Traversing

=== "C++"

    ```cpp
    // vector<int> nums;
    for (int i = 0; i < nums.size(); ++i) { ... }
    for (const int num : nums) { ... }

    // vector<string> words;
    for (const string& word : words) { ... }

    // string str;
    for (int i = 0; i < str.length(); ++i) { ... }
    for (const char c : str) { ... }

    // unordered_set<int> numsSet;
    for (const int num : numsSet) { ... }

    // unordered_map<char, int> lookup;
    for (const auto& [key, value] : lookup) { ... }

    // ListNode* head;
    for (ListNode* curr = head; curr != nullptr; curr = curr->next) { ... }
    ```

=== "Java"

    ```java
    // int[] nums;
    for (int i = 0; i < nums.length; ++i) { ... }
    for (final int num : nums) { ... }

    // List<String> words;
    for (const string& word : words) { ... }

    // String s;
    for (int i = 0; i < s.length(); ++i) { ... }
    for (final char c : s.toCharArray()) { ... }

    // Set<Integer> numsSet;
    for (final int num : numsSet) { ... }

    // Map<Character, Integer> lookup;
    for (Map.Entry<Character, Integer> entry : lookup) {
      final char key = entry.getKey();
      final int value = entry.getValue();
      ...
    }

    // ListNode head;
    for (ListNode curr = head; curr != null; curr = curr.next) { ... }
    ```

=== "Python"

    ```python
    # nums: list[int]
    for i in range(nums):
      pass
    for num in nums:
      pass
    for i, num in enumerate(nums):
      pass

    # words: List[str]
    for word in words:
      pass

    # s: str
    for i in range(len(s)):
      pass
    for c in s:
      pass
    for i, c in enumerate(s):
      pass

    # numsSet: set[int]
    for num in numsSet:
      pass

    # lookup: dict[str, int]
    for key, value in lookup.items():
      pass

    # head: ListNode
    curr = head
    while curr:
      curr = curr.next
    ```

### Miscellaneous

Always use _camelCase_ nomenclature when not listed above.

=== "C++"

    ```cpp
    int currNum = 0;
    int maxProfit = INT_MIN;
    TreeNode* currNode = nullptr;
    ```

=== "Java"

    ```java
    int currNum = 0;
    int maxProfit = Integer.MIN_VALUE;
    TreeNode currNode = null;
    ```

=== "Python"

    ```python
    currNum = 0
    maxProfit = math.inf
    currNode = None
    ```

When there's confliction in expression and function or reserved key word:

=== "C++"

    ```cpp
    mn, std::min()
    mx, std::max()
    ```

=== "Java"

    ```cpp
    mn, Math.min()
    mx, Math.max()
    ```

=== "Python"

    ```python
    mn, min
    mx, max
    summ, sum
    ```

When there are two maps/stacks, use meaningful names.

=== "C++"

    ```cpp
    unordered_map<char, int> countA;
    unordered_map<char, int> countB;
    ```

=== "Java"

    ```java
    Map<Character, Integer> countA = new HashMap<>();
    Map<Character, Integer> countB = new HashMap<>();
    ```

=== "Python"

    ```python
    countA = collections.Counter()
    countB = collections.Counter()
    ```

Others:

1. In C++, always prefer `str.length()` over `str.size()`.
1. In C++, `constexpr` is used if possible.
1. In C++ `const` is used if possible.
1. In C++, `const auto` structured binding is used when we iterate through a
   `unordered_map` or `map`.
1. In C++, `&` is used whenever possible except `int` and `char` because
   reference typically takes 4 bytes, while `int` takes 2/4 bytes and `char`
   takes 1 byte.
1. In C++, `std::ranges` is used where it enhances clarity and fits naturally
   with the code.
1. In C++ and Java, initialize a vector or an array with `0` or `false`
   **implicitly**.
1. In Java, `final` is used whenever makes sense.
1. Prefer to name variables in a "adjective + noun" order. For example,
   `maxLeft` is better than `leftMax`.
1. If a block is really small, for example, before a `bfs()` call, sometimes we
   don't add extra blank lines. This is not a hard rule.
