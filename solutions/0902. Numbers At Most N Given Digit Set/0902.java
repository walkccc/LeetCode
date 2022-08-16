class Solution {
  public int atMostNGivenDigitSet(String[] D, int N) {
    int ans = 0;
    String num = String.valueOf(N);

    for (int i = 1; i < num.length(); ++i)
      ans += Math.pow(D.length, i);

    for (int i = 0; i < num.length(); ++i) {
      boolean dHasSameNum = false;
      for (final String digit : D) {
        if (digit.charAt(0) < num.charAt(i))
          ans += Math.pow(D.length, num.length() - i - 1);
        else if (digit.charAt(0) == num.charAt(i))
          dHasSameNum = true;
      }
      if (!dHasSameNum)
        return ans;
    }

    return ans + 1;
  }
}
