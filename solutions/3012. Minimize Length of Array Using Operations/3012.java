class Solution {
  public int minimumArrayLength(int[] nums) {
    // Let the minimum number in the array `nums` be x.
    // * If there exists any element nums[i] where nums[i] % x > 0, a new
    //   minimum can be generated and all other numbers can be removed.
    // * If not, count the frequency of x in `nums`. For each pair of x, a 0 is
    //   generated which cannot be removed. Therefore, the result will be
    //   (frequency of x + 1) / 2.
    final int minNum = Arrays.stream(nums).min().getAsInt();
    if (Arrays.stream(nums).anyMatch(num -> num % minNum > 0))
      return 1;
    final int freq = (int) Arrays.stream(nums).filter(num -> num == minNum).count();
    return (freq + 1) / 2;
  }
}
