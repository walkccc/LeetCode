class Solution {
  public boolean isZeroArray(int[] nums, int[][] queries) {
    int[] line = new int[nums.length + 1];
    int decrement = 0;

    for (int[] query : queries) {
      final int l = query[0];
      final int r = query[1];
      ++line[l];
      --line[r + 1];
    }

    for (int i = 0; i < nums.length; ++i) {
      decrement += line[i];
      if (decrement < nums[i])
        return false;
    }

    return true;
  }
}
