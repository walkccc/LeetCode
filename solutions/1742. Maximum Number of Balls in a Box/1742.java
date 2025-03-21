class Solution {
  public int countBalls(int lowLimit, int highLimit) {
    final int maxDigitSum = 9 * 5; // 99999
    int ans = 0;
    int[] count = new int[maxDigitSum + 1];

    for (int num = lowLimit; num <= highLimit; ++num)
      ans = Math.max(ans, ++count[getDigitSum(num)]);

    return ans;
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
