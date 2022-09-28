class Solution {
 public:
  int countTriples(int n) {
    int ans = 0;
    unordered_set<int> squared;

    for (int i = 1; i <= n; ++i)
      squared.insert(i * i);

    for (const int a : squared)
      for (const int b : squared)
        if (squared.count(a + b))
          ++ans;

    return ans;
  }
};
