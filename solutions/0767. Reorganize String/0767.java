class Solution {
  public String reorganizeString(String S) {
    final int n = S.length();

    int[] count = new int[128];
    int maxCount = 0;
    char maxChar = '@';

    for (final char c : S.toCharArray())
      ++count[c];

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c] > maxCount) {
        maxCount = count[c];
        maxChar = c;
      }

    if (maxCount > (n + 1) / 2)
      return "";

    char[] ans = new char[n];

    // fill in 0, 2, 4, ... indices with the maxCount char
    while (count[maxChar]-- > 0)
      fillIn(ans, maxChar);

    // fill in remaining characters
    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c]-- > 0)
        fillIn(ans, c);

    return new String(ans);
  }

  private int i = 0; // ans's index

  private void fillIn(char[] ans, char c) {
    ans[i] = c;
    i += 2;
    if (i >= ans.length) // out of bound, reset the index to 1
      i = 1;
  }
}
