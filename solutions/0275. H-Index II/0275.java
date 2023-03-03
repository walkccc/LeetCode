class Solution {
  public int hIndex(int[] citations) {
    int l = 0;
    int r = citations.length;

    while (l < r) {
      final int m = (l + r) / 2;
      if (citations[m] >= citations.length - m)
        r = m;
      else
        l = m + 1;
    }

    return citations.length - l;
  }
}
