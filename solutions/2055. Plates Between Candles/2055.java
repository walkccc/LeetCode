class Solution {
  public int[] platesBetweenCandles(String s, int[][] queries) {
    int[] ans = new int[queries.length];
    List<Integer> indices = new ArrayList<>(); // indices of '|'

    for (int i = 0; i < s.length(); ++i)
      if (s.charAt(i) == '|')
        indices.add(i);

    for (int i = 0; i < queries.length; ++i) {
      final int left = queries[i][0];
      final int right = queries[i][1];
      final int l = firstGreaterEqual(indices, left);
      final int r = firstGreaterEqual(indices, right + 1) - 1;
      if (l < r) {
        final int lengthBetweenCandles = indices.get(r) - indices.get(l) + 1;
        final int numCandles = r - l + 1;
        ans[i] = lengthBetweenCandles - numCandles;
      }
    }

    return ans;
  }

  private int firstGreaterEqual(List<Integer> indices, int target) {
    final int i = Collections.binarySearch(indices, target);
    return i < 0 ? -i - 1 : i;
  }
}
