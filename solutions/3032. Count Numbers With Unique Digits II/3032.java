class Solution {
  public int numberCount(int a, int b) {
    int ans = 0;
    for (int num = a; num <= b; ++num)
      if (isUniqueDigits(num))
        ++ans;
    return ans;
  }

  private boolean isUniqueDigits(int num) {
    boolean[] seen = new boolean[10];
    while (num > 0) {
      final int digit = num % 10;
      if (seen[digit])
        return false;
      seen[digit] = true;
      num /= 10;
    }
    return true;
  }
}
