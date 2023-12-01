class Solution {
 public:
  // Same as 2927. Distribute Candies Among Children III
  int distributeCandies(int n, int limit) {
    const int limitPlusOne = limit + 1;
    const int oneChildExceedsLimit = ways(n - limitPlusOne);
    const int twoChildrenExceedLimit = ways(n - 2 * limitPlusOne);
    const int threeChildrenExceedLimit = ways(n - 3 * limitPlusOne);
    // Principle of Inclusion-Exclusion (PIE)
    return ways(n) - 3 * oneChildExceedsLimit + 3 * twoChildrenExceedLimit -
           threeChildrenExceedLimit;
  }

 private:
  // Returns the number of ways to distribute n candies to 3 children.
  int ways(int n) {
    if (n < 0)
      return 0;
    // Stars and bars method:
    // e.g. '**|**|*' means to distribute 5 candies to 3 children, where
    // stars (*) := candies and bars (|) := dividers between children.
    return nCk(n + 2, 2);
  }

  int nCk(int n, int k) {
    int ans = 1;
    for (int i = 1; i <= k; ++i)
      ans *= (n - i + 1);
    for (int i = 1; i <= k; ++i)
      ans /= i;
    return ans;
  }
};
