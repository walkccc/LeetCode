class Solution {
  public int maxScore(int[] nums) {
    nums = Arrays.stream(nums)
               .boxed()
               .sorted(Collections.reverseOrder())
               .mapToInt(Integer::intValue)
               .toArray();

    long prefix = 0;

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i];
      if (prefix <= 0)
        return i;
    }

    return nums.length;
  }
}
