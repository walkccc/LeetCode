class Solution {
  public int[] elementInNums(int[] nums, int[][] queries) {
    int[] ans = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      final int time = queries[i][0];
      final int index = queries[i][1];
      ans[i] = f(nums, time % (2 * nums.length), index);
    }

    return ans;
  }

  private int f(int[] A, int time, int index) {
    final int n = A.length;
    if (time < n) { // [0, 1, 2] -> [1, 2] -> [2]
      index += time;
      return index >= n ? -1 : A[index];
    } else { // [] -> [0] -> [0, 1]
      return index >= time - n ? -1 : A[index];
    }
  }
}
