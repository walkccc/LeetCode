class Solution {
  public int differenceOfSum(int[] nums) {
    final int elementSum = Arrays.stream(nums).sum();
    final int allDigitSum = getAllDigitSum(nums);
    return Math.abs(elementSum - allDigitSum);
  }

  private int getAllDigitSum(int[] nums) {
    int allDigitSum = 0;
    for (final int num : nums)
      allDigitSum += getDigitSum(num);
    return allDigitSum;
  }

  private int getDigitSum(int num) {
    int digitSum = 0;
    while (num > 0) {
      digitSum += num % 10;
      num /= 10;
    }
    return digitSum;
  }
}
