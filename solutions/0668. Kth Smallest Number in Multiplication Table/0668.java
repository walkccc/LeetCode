class Solution {
  public int findKthNumber(int m, int n, int k) {
    int l = 1;
    int r = m * n;

    while (l < r) {
      final int mid = (l + r) / 2;
      if (numsNoGreaterThan(m, n, mid) >= k)
        r = mid;
      else
        l = mid + 1;
    }

    return l;
  }

  private int numsNoGreaterThan(int m, int n, int target) {
    int count = 0;
    // for each row i, count # of numbers <= target
    for (int i = 1; i <= m; ++i)
      count += Math.min(target / i, n);
    return count;
  }
}
