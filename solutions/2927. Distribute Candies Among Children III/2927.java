class Solution {
  public long distributeCandies(int n, int limit) {
    final int limitPlusOne = limit + 1;
    final long oneChildExceedsLimit = ways(n - limitPlusOne);
    final long twoChildrenExceedLimit = ways(n - 2 * limitPlusOne);
    final long threeChildrenExceedLimit = ways(n - 3 * limitPlusOne);
    // Principle of Inclusion-Exclusion (PIE)
    return ways(n) - 3 * oneChildExceedsLimit + 3 * twoChildrenExceedLimit -
        threeChildrenExceedLimit;
  }

  private long ways(int n) {
    if (n < 0)
      return 0;
    // Stars and bars method:
    // e.g. '**|**|*' means to distribute 5 candies to 3 children, where
    // stars (*) := candies and bars (|) := dividers between children.
    return nCk(n + 2, 2);
  }

  private long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i)
      res = res * (n - i + 1) / i;
    return res;
  }
}
