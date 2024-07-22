class Solution {
  public int countLetters(String s) {
    int ans = 0;
    int dp = 0;        // the length of the running letter
    char letter = '@'; // the running letter

    for (final char c : s.toCharArray()) {
      if (c == letter) {
        ++dp;
      } else {
        dp = 1;
        letter = c;
      }
      // Add the number of substrings ending in the current letter.
      ans += dp;
    }

    return ans;
  }
}
