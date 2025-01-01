class Solution {
  public int secondHighest(String s) {
    int maxDigit = -1;
    int secondMaxDigit = -1;

    for (final char c : s.toCharArray())
      if (Character.isDigit(c)) {
        final int digit = Character.getNumericValue(c);
        if (digit > maxDigit) {
          secondMaxDigit = maxDigit;
          maxDigit = digit;
        } else if (maxDigit > digit && digit > secondMaxDigit) {
          secondMaxDigit = digit;
        }
      }

    return secondMaxDigit;
  }
}
