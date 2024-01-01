class Solution {
  // Same as 2829. Determine the Minimum Sum of a k-avoiding Array
  public int minimumPossibleSum(int n, int target) {
    // These are the unique pairs that sum up to target (k):
    // (1, k - 1), (2, k - 2), ..., (ceil(k / 2), floor(k / 2)).
    // Our optimal strategy is to select 1, 2, ..., floor(k / 2), and then
    // choose k, k + 1, ... if necessary, as selecting any number in the range
    // [ceil(k / 2), k - 1] will result in a pair summing up to k.
    final int mid = target / 2; // floor(k / 2)
    if (n <= mid)
      return (int) trapezoid(1, n);
    return (int) ((trapezoid(1, mid) + trapezoid(target, target + (n - mid - 1))) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  // Returns sum(a..b).
  private long trapezoid(long a, long b) {
    return (a + b) * (b - a + 1) / 2;
  }
}
