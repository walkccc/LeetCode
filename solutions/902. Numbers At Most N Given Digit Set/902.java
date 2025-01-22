class Solution {
  public int atMostNGivenDigitSet(String[] digits, int n) {
    int ans = 0;
    final String num = String.valueOf(n);

    for (int i = 1; i < num.length(); ++i)
      ans += (int) Math.pow(digits.length, i);

    for (int i = 0; i < num.length(); ++i) {
      boolean dHasSameNum = false;
      for (final String digit : digits) {
        if (digit.charAt(0) < num.charAt(i))
          ans += (int) Math.pow(digits.length, num.length() - i - 1);
        else if (digit.charAt(0) == num.charAt(i))
          dHasSameNum = true;
      }
      if (!dHasSameNum)
        return ans;
    }

    return ans + 1;
  }
}
