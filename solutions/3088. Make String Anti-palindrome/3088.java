class Solution {
  public String makeAntiPalindrome(String s) {
    final int n = s.length();
    int i = n / 2;
    char[] chars = s.toCharArray();
    Arrays.sort(chars);
    if (chars[i] != chars[n - i - 1])
      return new String(chars);

    int j = getFirstDiffIndexInSecondHalf(chars);
    while (chars[i] == chars[n - i - 1]) {
      if (j == n)
        return "-1";
      final char temp = chars[i];
      chars[i] = chars[j];
      chars[j] = temp;
      ++i;
      ++j;
    }

    return new String(chars);
  }

  // Returns the first index in chars[n / 2..n) that is different from the first
  // letter of the second half, chars[n / 2].
  private int getFirstDiffIndexInSecondHalf(char[] chars) {
    final int n = chars.length;
    final char firstLetter = chars[n / 2];
    int firstDiffIndex = n / 2;
    while (firstDiffIndex < n && chars[firstDiffIndex] == firstLetter)
      ++firstDiffIndex;
    return firstDiffIndex;
  }
}
