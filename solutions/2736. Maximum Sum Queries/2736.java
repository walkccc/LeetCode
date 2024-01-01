class Solution {
  public int[] maximumSumQueries(int[] nums1, int[] nums2, int[][] queries) {
    MyPair[] pairs = getPairs(nums1, nums2);
    IndexedQuery[] indexedQueries = getIndexedQueries(queries);
    int[] ans = new int[queries.length];
    List<Pair<Integer, Integer>> stack = new ArrayList<>(); // [(y, x + y)]

    int pairsIndex = 0;
    for (IndexedQuery indexedQuery : indexedQueries) {
      final int queryIndex = indexedQuery.queryIndex;
      final int minX = indexedQuery.minX;
      final int minY = indexedQuery.minY;
      while (pairsIndex < pairs.length && pairs[pairsIndex].x >= minX) {
        MyPair pair = pairs[pairsIndex++];
        // x + y is a better candidate. Given that x is decreasing, the
        // condition "x + y >=  stack.get(stack.size() - 1).getValue()" suggests
        // that y is relatively larger, thereby making it a better candidate.
        final int x = pair.x;
        final int y = pair.y;
        while (!stack.isEmpty() && x + y >= stack.get(stack.size() - 1).getValue())
          stack.remove(stack.size() - 1);
        if (stack.isEmpty() || y > stack.get(stack.size() - 1).getKey())
          stack.add(new Pair<>(y, x + y));
      }
      final int j = firstGreaterEqual(stack, minY);
      ans[queryIndex] = j == stack.size() ? -1 : stack.get(j).getValue();
    }

    return ans;
  }

  private record MyPair(int x, int y){};
  private record IndexedQuery(int queryIndex, int minX, int minY){};

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

  private MyPair[] getPairs(int[] nums1, int[] nums2) {
    MyPair[] pairs = new MyPair[nums1.length];
    for (int i = 0; i < nums1.length; ++i)
      pairs[i] = new MyPair(nums1[i], nums2[i]);
    Arrays.sort(pairs, (a, b) -> b.x - a.x);
    return pairs;
  }

  private IndexedQuery[] getIndexedQueries(int[][] queries) {
    IndexedQuery[] indexedQueries = new IndexedQuery[queries.length];
    for (int i = 0; i < queries.length; ++i)
      indexedQueries[i] = new IndexedQuery(i, queries[i][0], queries[i][1]);
    Arrays.sort(indexedQueries, (a, b) -> b.minX - a.minX);
    return indexedQueries;
  }
}
