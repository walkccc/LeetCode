class Solution {
  public int minimumLevels(int[] possible) {
    final int n = possible.length;
    final int[] nums = getNums(possible);
    int[] prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + nums[i];

    for (int i = 1; i < n; ++i)
      if (prefix[i] > prefix[n] - prefix[i])
        return i;

    return -1;
  }

  private int[] getNums(int[] possible) {
    int[] nums = new int[possible.length];
    for (int i = 0; i < possible.length; ++i)
      nums[i] = possible[i] == 0 ? -1 : 1;
    return nums;
  }
}
