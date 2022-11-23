class Solution {
  public int[] minDifference(int[] nums, int[][] queries) {
    int[] ans = new int[queries.length];
    List<Integer>[] numToIndices = new List[101];

    for (int i = 1; i <= 100; ++i)
      numToIndices[i] = new ArrayList<>();

    for (int i = 0; i < nums.length; ++i)
      numToIndices[nums[i]].add(i);

    if (numToIndices[nums[0]].size() == nums.length) {
      Arrays.fill(ans, -1);
      return ans;
    }

    for (int i = 0; i < queries.length; ++i) {
      final int l = queries[i][0];
      final int r = queries[i][1];
      int prevNum = -1;
      int minDiff = 101;
      for (int num = 1; num <= 100; ++num) {
        List<Integer> indices = numToIndices[num];
        final int j = firstGreaterEqual(indices, l);
        if (j == indices.size() || indices.get(j) > r)
          continue;
        if (prevNum != -1)
          minDiff = Math.min(minDiff, num - prevNum);
        prevNum = num;
      }
      ans[i] = minDiff == 101 ? -1 : minDiff;
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
