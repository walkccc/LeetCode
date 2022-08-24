# Style Guide

> This document is discussed with [@hsins](https://github.com/hsins).
>
> See the definition of [Convention over configuration in Wikipedia](https://en.wikipedia.org/wiki/Convention_over_configuration).

## Disclaimer

### General

- We adopt `lowerCamelCase` for both functions and variables, which is against the rule of [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#General_Naming_Rules) and [PEP 8 -- Style Guide for Python Code](https://www.python.org/dev/peps/pep-0008/#naming-conventions). However, to be consistent with the LeetCode OJ system, which uses `lowerCamelCase` for over 99% of the time, we stick with `lowerCamelCase` in this case. Remember the most important thing is to be consistent all the time.
- We omit importing and brackets, and this is for shorter paragraph. In a real situation, retain importing let you quickly know where is this function/variable from and brackets make the indentation safer, so you might keep both of them.

### C++

- Code can't be compiled, it's just for demonstrating purposes.
- Even though there is [`auto` keyword in C++ 11](https://en.cppreference.com/w/cpp/language/auto), for types like `int` and `char`, we tend to explicitly declare them. However, you might use `auto` most of the time in the real world.
- We skip including.
- We use `int` to traverse the array most of the time for simplicity. However, you should note the difference between `size_t` and `int`, and in the real world, that matters.
- We omit `std::` to access the standard library for a short paragraph.

### Java

- Code can't be compiled, it's just for demonstrating purposes.
- Even though there is `var` keyword in Java, for types like `int` and `char`, we tend to explicitly declare them so people can have an idea of what the type is at first glance.
- We skip importing.

### Python

- We omit prefixes like `collections.` and `math.`. However, this might not be a good practice. Just want to keep the paragraph short.
- We prefix private functions with `_` and this might seem tedious. However, we tend to use something like Mypy and Pyre to do static type checking in the real world.
- We pass the argument `--indent-size=2` to [autopep8](https://pypi.org/project/autopep8/) for a better viewing experience.

## Fundamental

### Rules

- **Class**: `UpperCamelCase`
- **Function**: `lowerCamelCase`
- **Variable**: `lowerCamelCase`
- **Constant**: `UPPERCASE` with underline
- **Field**: `lowerCamelCase`
- **Database**: `SELECT * FROM name_table`

### Examples

```cpp
// Class
class MyClass { ... }

// Function
function myFunction() { ... }

// Variable
int myVariable;

// Constant
#define MY_CONSTANT;

// Database Table
SELECT * FROM my_table
```

## Template

### Rules

- There should only be one public function.
- Declare the variables in the proper scope as slow as possible.

  - Declare `const` variables as soon as possible.
  - Declare `ans` as soon as possible.
  - Since LeetCode is just an online judge system rather than a big project, we don't scatter all variables in different sections. However, we still sort the variables based on the time we first use each of them.

- Code section (there should be one blank line between each sections.)

  - `public`

    1. boundary conditions
    2. initial variables
    3. There may be many kernels separated with one blank line, but there shouldn't be any blank line in each kernel.
    4. return

  - `private`

    1. private variables
    2. private function(s)

## Schematic Template

> We use C++ to demo the idea.

- No blank lines between variables initialization.
- Blank one single line between each section. **However, if there's no sec 12**, no blank line between **sec 11** and **sec 13**.
- If the last statement is not a paragraph (`for` loop most of the case), then no blank lines between it and the `return` statement.

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

Example ([873. Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)):

- code:

  ```cpp
  class Solution {
  public:
    int lenLongestFibSubseq(vector<int>& A) {
      const int n = A.size();
      int ans = 0;
      vector<vector<int>> dp(n, vector<int>(n, 2));
      unordered_map<int, int> numToIndex;

      for (int i = 0; i < n; ++i)
        numToIndex[A[i]] = i;

      for (int j = 0; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          const int ai = A[k] - A[j];
          if (ai < A[j] && numToIndex.count(ai)) {
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
    int lenLongestFibSubseq(vector<int>& A) {
      // Only get the value of size or length
      //   when we use it twice or more times.
      // Add `const`, and separate this line from next section a blank line.
      const int n = A.size();
      // Declare the variables in the proper scope as slow as possible.
      //   Declare `ans` as soon as possible.
      //   General Order:
      //     ans -> dp -> STL -> pointers (TBD)
      //
      //   Graph Order:
      //     ans -> graph -> inDegree -> state -> q -> seen
      int ans = 0;
      vector<vector<int>> dp(n, vector<int>(n, 2));
      unordered_map<int, int> numToIndex;

      for (int i = 0; i < n; ++i)
        numToIndex[A[i]] = i;

      for (int j = 0; j < n; ++j)
        for (int k = j + 1; k < n; ++k) {
          const int ai = A[k] - A[j]; // use const
          if (ai < A[j] && numToIndex.count(ai)) {
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
if (l1 || l2) { ... }
if (!l1 || !l2) { ... }

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
deque<TreeNode*> q;
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
Stack<Character> stack = new Stack<>();
Queue<Integer> q = new LinkedList<>();
Deque<Integer> q = new ArrayDeque<>();
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
2. Use `i`, `j`, `k` in the loop, in that order.

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
for (const auto& word : words) { ... }

// string str;
for (int i = 0; i < str.length(); ++i) { ... }
for (const char c : str) { ... }

// unordered_set<int> numsSet;
for (const int num : numsSet) { ... }

// structured binding
// unordered_map<char, int> map;
for (const auto& [key, value] : map) { ... }

// ListNode* head;
for (auto curr = head; curr; curr = curr->next) { ... }
```

## Others

1. Always prefer to use `str.length()` over `str.size()`.
2. Always use _camelCase_ nomenclature when not listed above.

   ```cpp
   // C++
   int currNum;
   int maxProfit;
   TreeNode* currNode;
   ```

3. When there's confliction in expression and function or reserved key word:

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

4. When there are two maps/stacks, use meaningful names.

   ```cpp
   // C++
   unordered_map<char, int> countA;
   unordered_map<char, int> countB;
   ```

5. When we need to count something, use `sum`, `count` and `total`, in that order.
6. Initialize vector with `0` or `false` **implicitly**.
7. `constexpr` is used if possible.
8. `const` is used if we get value of `size()` or `length()`.
9. `const auto` is used when we iterate through a `map`.
10. Use `&` whenever possible except `int` and `char` because reference typically takes 4 bytes, while `int` takes 2/4 bytes and `char` takes 1 byte.
11. Prefer to name variables in a "adjective + noun" order. For example, `maxLeft` is better than `leftMax`.
12. If a block is really small, for example, before a `bfs()` call, sometimes we don't add extra blank lines.
