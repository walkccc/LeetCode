class Solution {
  public int longestPalindrome(String[] words) {
    int ans = 0;
    int[][] count = new int[26][26];

    for (final String word : words) {
      final int i = word.charAt(0) - 'a';
      final int j = word.charAt(1) - 'a';
      if (count[j][i] > 0) {
        ans += 4;
        --count[j][i];
      } else {
        ++count[i][j];
      }
    }

    for (int i = 0; i < 26; ++i)
      if (count[i][i] > 0)
        return ans + 2;

    return ans;
  }
}
