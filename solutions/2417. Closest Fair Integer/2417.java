class Solution {
  public int closestFair(int n) {
    final int digitsCount = String.valueOf(n).length();
    return digitsCount % 2 == 0 ? getEvenDigits(n) : (int) getOddDigits(digitsCount);
  }

  private long getOddDigits(int digitsCount) {
    final int zeros = (digitsCount + 1) / 2;
    final int ones = (digitsCount - 1) / 2;
    return Integer.valueOf('1' + "0".repeat(zeros) + "1".repeat(ones));
  }

  private int getEvenDigits(int n) {
    final int digitsCount = String.valueOf(n).length();
    final long maxNum = Long.valueOf('1' + "0".repeat(digitsCount));
    for (long num = n; num < maxNum; ++num)
      if (isValidNum(num))
        return (int) num;
    return (int) getOddDigits(digitsCount + 1);
  }

  private boolean isValidNum(long num) {
    int count = 0;
    for (final char c : String.valueOf(num).toCharArray())
      count += (c - '0') % 2 == 0 ? 1 : -1;
    return count == 0;
  }
}
