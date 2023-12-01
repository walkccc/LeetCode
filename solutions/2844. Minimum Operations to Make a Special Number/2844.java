class Solution {
  public int minimumOperations(String num) {
    final int n = num.length();
    boolean seenFive = false;
    boolean seenZero = false;

    for (int i = n - 1; i >= 0; --i) {
      if (seenZero && num.charAt(i) == '0') // '00'
        return n - i - 2;
      if (seenZero && num.charAt(i) == '5') // '50'
        return n - i - 2;
      if (seenFive && num.charAt(i) == '2') // '25'
        return n - i - 2;
      if (seenFive && num.charAt(i) == '7') // '75'
        return n - i - 2;
      seenZero = seenZero || num.charAt(i) == '0';
      seenFive = seenFive || num.charAt(i) == '5';
    }

    return seenZero ? n - 1 : n;
  }
}
