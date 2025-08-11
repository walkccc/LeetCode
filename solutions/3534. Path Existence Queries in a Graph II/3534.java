class Solution {
  public int[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
    int[] ans = new int[queries.length];
    int[] indexMap = new int[n];
    int[] sortedNums = new int[n];
    Pair<Integer, Integer>[] sortedNumAndIndexes = new Pair[n];

    for (int i = 0; i < n; ++i)
      sortedNumAndIndexes[i] = new Pair<>(nums[i], i);

    Arrays.sort(sortedNumAndIndexes, Comparator.comparingInt(Pair::getKey));

    for (int i = 0; i < n; ++i) {
      final int num = sortedNumAndIndexes[i].getKey();
      final int sortedIndex = sortedNumAndIndexes[i].getValue();
      sortedNums[i] = num;
      indexMap[sortedIndex] = i;
    }

    final int maxLevel = Integer.SIZE - Integer.numberOfLeadingZeros(n) + 1;
    // jump[i][j] := the index of the j-th ancestor of i
    int[][] jump = new int[n][maxLevel];

    int right = 0;
    for (int i = 0; i < n; ++i) {
      while (right + 1 < n && sortedNums[right + 1] - sortedNums[i] <= maxDiff)
        ++right;
      jump[i][0] = right;
    }

    for (int level = 1; level < maxLevel; ++level)
      for (int i = 0; i < n; ++i) {
        final int prevJump = jump[i][level - 1];
        jump[i][level] = jump[prevJump][level - 1];
      }

    for (int i = 0; i < queries.length; ++i) {
      final int u = queries[i][0];
      final int v = queries[i][1];
      final int uIndex = indexMap[u];
      final int vIndex = indexMap[v];
      final int start = Math.min(uIndex, vIndex);
      final int end = Math.max(uIndex, vIndex);
      final int res = minJumps(jump, start, end, maxLevel - 1);
      ans[i] = res == Integer.MAX_VALUE ? -1 : res;
    }

    return ans;
  }

  // Returns the minimum number of jumps from `start` to `end` using binary
  // lifting.
  private int minJumps(int[][] jump, int start, int end, int level) {
    if (start == end)
      return 0;
    if (jump[start][0] >= end)
      return 1;
    if (jump[start][level] < end)
      return Integer.MAX_VALUE;
    int j = level;
    for (; j >= 0; --j)
      if (jump[start][j] < end)
        break;
    return (1 << j) + minJumps(jump, jump[start][j], end, j);
  }
}
