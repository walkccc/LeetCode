class Solution {
  public boolean[] isArraySpecial(int[] nums, int[][] queries) {
    boolean[] ans = new boolean[queries.length];
    // parityIds[i] := the id of the parity group that nums[i] belongs to
    int[] parityIds = new int[nums.length];
    int id = 0;
    parityIds[0] = id;

    for (int i = 1; i < nums.length; ++i) {
      if (nums[i] % 2 == nums[i - 1] % 2)
        ++id;
      parityIds[i] = id;
    }

    for (int i = 0; i < queries.length; ++i) {
      final int from = queries[i][0];
      final int to = queries[i][1];
      ans[i] = parityIds[from] == parityIds[to];
    }

    return ans;
  }
}
