class Solution {
  public int addMinimum(String word) {
    final char[] letters = new char[] {'a', 'b', 'c'};
    int ans = 0;
    int i = 0;

    while (i < word.length())
      for (final char c : letters) {
        if (i < word.length() && word.charAt(i) == c)
          ++i;
        else
          ++ans;
      }

    return ans;
  }
};
