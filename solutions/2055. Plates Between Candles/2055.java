class Solution {
  public int[] platesBetweenCandles(String s, int[][] queries) {
    int[] ans = new int[queries.length];
    List<Integer> A = new ArrayList<>(); // indices of '|'

    for (int i = 0; i < s.length(); ++i)
      if (s.charAt(i) == '|')
        A.add(i);

    for (int i = 0; i < queries.length; ++i) {
      final int left = queries[i][0];
      final int right = queries[i][1];
      final int l = firstGreaterEqual(A, left);
      final int r = firstGreaterEqual(A, right + 1) - 1;
      if (l < r) {
        final int lengthBetweenCandles = A.get(r) - A.get(l) + 1;
        final int numCandles = r - l + 1;
        ans[i] = lengthBetweenCandles - numCandles;
      }
    }

    return ans;
  }

  private int firstGreaterEqual(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
