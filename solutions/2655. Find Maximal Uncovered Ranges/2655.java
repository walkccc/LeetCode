class Solution {
  public int[][] findMaximalUncoveredRanges(int n, int[][] ranges) {
    List<int[]> ans = new ArrayList<>();
    int start = 0;

    Arrays.sort(ranges, (a, b) -> a[0] - b[0]);

    for (int[] range : ranges) {
      final int l = range[0];
      final int r = range[1];
      if (start < l)
        ans.add(new int[] {start, l - 1});
      if (start <= r)
        start = r + 1;
    }

    if (start < n)
      ans.add(new int[] {start, n - 1});

    return ans.stream().toArray(int[][] ::new);
  }
}
