class Solution {
  // Returns the number of ways to distribute n candies to 3 children.
  public int distributeCandies(int n, int limit) {
    final int limitPlusOne = limit + 1;
    final int oneChildExceedsLimit = ways(n - limitPlusOne);
    final int twoChildrenExceedLimit = ways(n - 2 * limitPlusOne);
    final int threeChildrenExceedLimit = ways(n - 3 * limitPlusOne);
    // Principle of Inclusion-Exclusion (PIE)
    return ways(n) - 3 * oneChildExceedsLimit + 3 * twoChildrenExceedLimit -
        threeChildrenExceedLimit;
  }

  private int ways(int n) {
    if (n < 0)
      return 0;
    // Stars and bars method:
    // e.g. '**|**|*' means to distribute 5 candies to 3 children, where
    // stars (*) := candies and bars (|) := dividers between children.
    return nCk(n + 2, 2);
  }

  private int nCk(int n, int k) {
    int ans = 1;
    for (int i = 1; i <= k; ++i)
      ans *= (n - i + 1);
    for (int i = 1; i <= k; ++i)
      ans /= i;
    return ans;
  }
}
