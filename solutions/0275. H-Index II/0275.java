class Solution {
  public int hIndex(int[] citations) {
    final int n = citations.length;
    int l = 0;
    int r = n;

    while (l < r) {
      final int m = (l + r) / 2;
      if (citations[m] >= n - m)
        r = m;
      else
        l = m + 1;
    }

    return n - l;
  }
}
