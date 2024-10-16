public class Solution {
  public int numberOfSteps(int num) {
    if (num == 0)
      return 0;
    final int subtractSteps = Integer.bitCount(num);
    final int divideSteps = 31 - Integer.numberOfLeadingZeros(num);
    return subtractSteps + divideSteps;
  }
}
