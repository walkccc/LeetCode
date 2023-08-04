class Solution {
  public int[] maximumSumQueries(int[] nums1, int[] nums2, int[][] queries) {
    List<MyPair> pairs = getPairs(nums1, nums2);
    List<IndexAndQuery> indexAndQueries = getIndexAndQueries(queries);
    int[] ans = new int[queries.length];
    List<Pair<Integer, Integer>> stack = new ArrayList<>(); // [(y, x + y)]

    int i = 0;
    for (IndexAndQuery indexAndQuery : indexAndQueries) {
      final int index = indexAndQuery.index;
      final int minX = indexAndQuery.minX;
      final int minY = indexAndQuery.minY;
      while (i < pairs.size() && pairs.get(i).x >= minX) {
        MyPair pair = pairs.get(i++);
        // x + y is a better candidate. Given that x is decreasing, the
        // condition "x + y >= stack.back().second" suggests that y is
        // relatively larger, thereby making it a better candidate.
        final int x = pair.x;
        final int y = pair.y;
        while (!stack.isEmpty() && x + y >= stack.get(stack.size() - 1).getValue())
          stack.remove(stack.size() - 1);
        if (stack.isEmpty() || y > stack.get(stack.size() - 1).getKey())
          stack.add(new Pair<>(y, x + y));
      }

      final int j = firstGreaterEqual(stack, minY);
      ans[index] = j == stack.size() ? -1 : stack.get(j).getValue();
    }

    return ans;
  }

  private record MyPair(int x, int y){};
  private record IndexAndQuery(int index, int minX, int minY){};

  private int firstGreaterEqual(List<Pair<Integer, Integer>> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m).getKey() >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

  private List<MyPair> getPairs(int[] nums1, int[] nums2) {
    List<MyPair> pairs = new ArrayList<>();
    for (int i = 0; i < nums1.length; ++i)
      pairs.add(new MyPair(nums1[i], nums2[i]));
    pairs.sort((a, b) -> b.x - a.x);
    return pairs;
  }

  private List<IndexAndQuery> getIndexAndQueries(int[][] queries) {
    List<IndexAndQuery> indexAndQueries = new ArrayList<>();
    for (int i = 0; i < queries.length; ++i)
      indexAndQueries.add(new IndexAndQuery(i, queries[i][0], queries[i][1]));
    indexAndQueries.sort((a, b) -> b.minX - a.minX);
    return indexAndQueries;
  }
}
