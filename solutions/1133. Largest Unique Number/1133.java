class Solution {
  public int largestUniqueNumber(int[] nums) {
    final int MAX = 1000;
    int[] count = new int[MAX + 1];

    for (final int num : nums)
      ++count[num];

    for (int num = MAX; num >= 0; --num)
      if (count[num] == 1)
        return num;

    return -1;
  }
}
