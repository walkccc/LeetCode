class Solution {
  public int countLetters(String s) {
    int ans = 0;
    int dp = 0;        // length of the running letter
    char letter = '@'; // running letter

    for (final char c : s.toCharArray()) {
      if (c == letter) {
        ++dp;
      } else {
        dp = 1;
        letter = c;
      }
      // Add # of substrings ending at the current letter.
      ans += dp;
    }

    return ans;
  }
}
