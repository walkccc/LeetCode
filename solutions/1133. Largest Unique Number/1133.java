class Solution {
  public int largestUniqueNumber(int[] nums) {
    final int kMax = 1000;
    int[] count = new int[kMax + 1];

    for (final int num : nums)
      ++count[num];

    for (int num = kMax; num >= 0; --num)
      if (count[num] == 1)
        return num;

    return -1;
  }
}
