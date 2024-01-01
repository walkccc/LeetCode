# Style Guide

> This document has been reviewed and discussed with
> [@hsins](https://github.com/hsins).
>
> For further reading, please see the definition of
> [Convention over configuration in Wikipedia](https://en.wikipedia.org/wiki/Convention_over_configuration).

## Disclaimer

### General

- In our coding convention, we use `lowerCamelCase` for both functions and
  variables. While this may deviate from the rules laid out in the
  [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#General_Naming_Rules)
  and
  [PEP 8 -- Style Guide for Python Code](https://www.python.org/dev/peps/pep-0008/#naming-conventions),
  it is done to maintain consistency with the LeetCode OJ system, which employs
  `lowerCamelCase ` for over 99% of the time. Remember, the most important thing
  is to be consistent at all times.
- In code snippets, import statements and brackets may be omitted for brevity
  (arguably), but they should be retained in real-world coding situations for
  clarity and maintainability.

### SQL

- The naming of LeetCode is quite a mess and inconsistently uses plurals and
  singulars together. I'll use my best judgment to name tables in
  `UpperCamelCase` in the plural form and fields in `lower_snake_case`.
- Proper indentation will be taken care of and treated seriously.
- No puzzling table abbreviation.

### C++

- The code is only for demonstration and cannot be compiled.
- Explicitly declaring types such as `int`, `char`, and `string` is often
  preferable over using the `auto` keyword introduced in C++ 11.
- `#include` statements are omitted in code snippets for brevity.
- Understanding the difference between `size_t` and `int` is crucial when
  traversing arrays in practical applications, as it can affect the outcome.
- Qualifying with `std::` prefix when accessing standard libraries is
  recommended for readability and maintainability in real-world coding
  situations, as it clearly indicates the source of the identifier being used.

### Java

- The code is only for demonstration and cannot be compiled.
- Explicitly declaring types such as `int`, `char`, and `String` is often
  preferable over using the `var` keyword introduced Java 10.
- `import` statements are omitted in code snippets for brevity.

### Python

- Private functions are prefixed with `_`, which may seem tedious. However, in
  the real world, we use tools like [Mypy](https://github.com/python/mypy),
  [Pytype](https://github.com/google/pytype), and
  [Pyre](https://github.com/facebook/pyre-check) for static type checking.
- We pass the argument `--indent-size=2` to
  [autopep8](https://pypi.org/project/autopep8/) for a better viewing
  experience.
- `import` statements are omitted in code snippets for brevity.

## Fundamental

### Rules

- **Class**: `UpperCamelCase`
- **Function**: `lowerCamelCase`
- **Variable**: `lowerCamelCase`
- **Constant**: `kUpperCamelCase`

### Examples in C++

```cpp
// Class
class MyClass { ... }

// Function
function myFunction() { ... }

// Variable
int myVariable;

// Constant
constexpr int kMod = 1'000'000'007;
```

## Template

### Rules

- There should only be one public function.
- Declare the variables in the proper scope as slow as possible.

  - Declare `const` variables as soon as possible.
  - Declare `ans` as soon as possible.
  - Since LeetCode is just an online judge system rather than a big project, we
    don't scatter all variables in different sections. However, we still sort
    the variables based on the time we first use each of them.

- Code section (there should be one blank line between each sections.)

  - `public`

    1. boundary conditions
    1. initial variables
    1. There may be many kernels separated with one blank line, but there
       shouldn't be any blank line in each kernel.
    1. return

  - `private`

    1. private variables
    1. private function(s)

## Schematic Template

> We use C++ to demonstrate the idea, and the same concepts apply to Java and
> Python as well.

- No blank lines between variables initialization.
- Blank one single line between each section. **However, if there's no sec 12**,
  no blank line between **sec 11** and **sec 13**.
- If the last statement is not a paragraph (`for` loop most of the case), then
  no blank lines between it and the `return` statement.

```cpp
class Solution {
 public:
  // There should only be one public function.
  func() {
    // (sec 0) boundary conditions

    // (sec 1) initial variables
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

  // private function(s)
  helper() { ... }

  dfs() { ... }
};
```

Example
([873. Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)):

- code:

  ```cpp
  class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
      const int n = arr.size();
      int ans = 0;
      vector<vector<int>> dp(n, vector<int>(n, 2));
      unordered_map<int, int> numToIndex;

      for (int i = 0; i < n; ++i)
        numToIndex[arr[i]] = i;

      for (int j = 0; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          const int ai = arr[k] - arr[j];
          if (ai < arr[j] && numToIndex.count(ai)) {
            const int i = numToIndex[ai];
            dp[j][k] = dp[i][j] + 1;
            ans = max(ans, dp[j][k]);
          }
        }

      return ans;
    }
  };
  ```

- code (explanation):

  ```cpp
  class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
      // Only get the value of size or length
      //   when we use it twice or more times.
      // Add `const`, and separate this line from next section a blank line.
      const int n = arr.size();
      // Declare the variables in the proper scope as slow as possible.
      //   Declare `ans` as soon as possible.
      //   General Order:
      //     ans -> dp -> STL -> pointers (TBD)
      //
      //   Graph Order:
      //     ans -> graph -> inDegrees -> state -> q -> seen
      int ans = 0;
      vector<vector<int>> dp(n, vector<int>(n, 2));
      unordered_map<int, int> numToIndex;

      for (int i = 0; i < n; ++i)
        numToIndex[arr[i]] = i;

      for (int j = 0; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          const int ai = arr[k] - arr[j]; // use const
          if (ai < arr[j] && numToIndex.count(ai)) {
            const int i = numToIndex[ai]; // use const
            dp[j][k] = dp[i][j] + 1;
            ans = max(ans, dp[j][k]);
          }
        }

      return ans;
    }
  };
  ```

## Boundary Conditions

```cpp
// Linked-List
if (l1 == nullptr && l2 == nullptr) { ... }
if (l1 != nullptr || l2 != nullptr) { ... }

// String
if (str.empty()) { ... }
if (str.length() <= 2) { ... }

// Vector
if (vec.size() <= 2) { ... }
```

## Return Value

```cpp
return ans;
return {};
```

## Data Structures

```cpp
// C++
unordered_set<string> seen;
unordered_map<char, int> count; // numToIndex, prefixToIndex
vector<int> count; // sometimes it's a better choice than `unordered_map`
stack<char> stack;
queue<TreeNode*> q;
deque<TreeNode*> dq;
auto compare = [](const ListNode* a, const ListNode* b) {
  return a->val > b->val;
};
priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
```

```java
// Java
Set<String> seen = new HashSet<>();
Map<Character, Integer> count = new HashMap<>();
int[] count = new int[n];
Deque<Character> stack = new ArrayDeque<>(); // Do not use Stack.
Queue<Integer> q = new LinkedList<>();
Deque<Integer> dq = new ArrayDeque<>();
Queue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);
```

```python
# Python
seen = set() # or wordSet = set() if you like
count = {}
count = collections.defaultdict(int)
count = collections.defaultdict(list)
count = collections.Counter()
q = collections.deque([root])
q = collections.deque([root])
stack = []
minHeap = []
```

## Two Pointers / Sliding Windows

1. Always prefer to _one_ character to represent index variables.
1. Use `i`, `j`, `k` in the loop, in that order.

```cpp
int i = 0;
for (const int num : nums) { ... }
```

```cpp
for (int i = 0, j = 0; i < n; ++i) { ... }
```

```cpp
int k = 0;
for (int i = 0; i < n; ++i)
  for (int j = i; j < n; ++j) { ... }
```

```cpp
int l = 0;
int r = nums.size() - 1;
```

## Union Find

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

## Graph / Tree

- If a graph has a clear tree structure, we name it a `tree`. Otherwise, we name
  it a `graph`.
- Always use `(u, v)` to represent an edge regardless what is stated in the
  problem.

```cpp
vector<vector<int>> graph(n);

for (const vector<int>& edge : edges) {
  const int u = edge[0];
  const int v = edge[1];
  graph[u].push_back(v);
  graph[v].push_back(u);
}
```

## Dijkstra

```cpp
void dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
  vector<int> dist(graph.size(), INT_MAX);
  using P = pair<int, int>;  // (d, u)
  priority_queue<P, vector<P>, greater<>> minHeap;

  dist[src] = 0;
  minHeap.emplace(0, src);

  while (!minHeap.empty()) {
    const auto [d, u] = minHeap.top();
    minHeap.pop();
    for (const auto& [v, w] : graph[u])
      if (d + w < dist[v]) {
        dist[v] = d + w;
        minHeap.emplace(dist[v], v);
      }
  }
}
```

## Binary Search

1. Always prefer to _one_ character to represent index variables.
2. Always prefer to use `[l, r)` pattern.

```cpp
int l = 0;
int r = nums.size();  // or nums.size() - 1

while (l < r) {
  const int m = l + (r - l) / 2;
  if (f(m))    // optional
    return m;  // optional
  if (g(m))
    l = m + 1;  // new range [m + 1, r)
  else
    r = m;  // new range [l, m)
}

return l;  // nums[l]
```

## ListNode

```cpp
ListNode dummy(0); // allocated on stack instead of heap

ListNode* curr;
ListNode* prev;
ListNode* next;

ListNode* slow;
ListNode* fast;

ListNode* head;
ListNode* tail;

ListNode* l1;
ListNode* l2;
```

## 2D Vector / 2 Strings

```cpp
// 2D Vector
const int m = matrix.size();
const int n = matrix[0].size();

// if there're two strings
const int m = str1.length();
const int n = str2.length();

// if there's only a string
const int n = str.length();
```

## Traversing

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

// structured binding
// unordered_map<char, int> map;
for (const auto& [key, value] : map) { ... }

// ListNode* head;
for (ListNode* curr = head; curr; curr = curr->next) { ... }
```

## Others

1. Always prefer to use `str.length()` over `str.size()`.
1. Always use _camelCase_ nomenclature when not listed above.

   ```cpp
   // C++
   int currNum;
   int maxProfit;
   TreeNode* currNode;
   ```

1. When there's confliction in expression and function or reserved key word:

   ```cpp
   // C++
   mini, std::min()
   maxi, std::max()
   ```

   ```python
   # Python
   mini, min
   maxi, max
   summ, sum
   ```

1. When there are two maps/stacks, use meaningful names.

   ```cpp
   // C++
   unordered_map<char, int> countA;
   unordered_map<char, int> countB;
   ```

1. When we need to count something, use `sum`, `count` and `total`, in that
   order.
1. Initialize vector with `0` or `false` **implicitly**.
1. `constexpr` is used if possible.
1. `const` is used if we get value of `size()` or `length()`.
1. `const auto` is used when we iterate through a `unordered_map` or `map`.
1. Use `&` whenever possible except `int` and `char` because reference typically
   takes 4 bytes, while `int` takes 2/4 bytes and `char` takes 1 byte.
1. Prefer to name variables in a "adjective + noun" order. For example,
   `maxLeft` is better than `leftMax`.
1. If a block is really small, for example, before a `bfs()` call, sometimes we
   don't add extra blank lines.
