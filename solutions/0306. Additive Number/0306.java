class Solution {
  public boolean isAdditiveNumber(String num) {
    final int n = num.length();

    // num[0..i] = firstNum
    for (int i = 0; i < n / 2; ++i) {
      if (i > 0 && num.charAt(0) == '0')
        return false;
      final long firstNum = Long.parseLong(num.substring(0, i + 1));
      // num[i + 1..j] = secondNum
      // len(thirdNum) >= max(len(firstNum), len(secondNum))
      for (int j = i + 1; Math.max(i, j - i) < n - j; ++j) {
        if (j > i + 1 && num.charAt(i + 1) == '0')
          break;
        final long secondNum = Long.parseLong(num.substring(i + 1, j + 1));
        if (dfs(num, firstNum, secondNum, j + 1))
          return true;
      }
    }

    return false;
  }

  private boolean dfs(final String num, long firstNum, long secondNum, long s) {
    if (s == num.length())
      return true;

    final long thirdNum = firstNum + secondNum;
    final String thirdNumStr = String.valueOf(thirdNum);
    return num.indexOf(thirdNumStr, (int) s) == s &&
        dfs(num, secondNum, thirdNum, s + thirdNumStr.length());
  }
}
