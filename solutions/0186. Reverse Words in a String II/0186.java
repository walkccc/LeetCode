class Solution {
  public void reverseWords(char[] s) {
    reverse(s, 0, s.length - 1); // Reverse the whole string.
    reverseWords(s, s.length);   // Reverse each word.
  }

  private void reverse(char[] s, int l, int r) {
    while (l < r) {
      final char c = s[l];
      s[l++] = s[r];
      s[r--] = c;
    }
  }

  private void reverseWords(char[] s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && s[i] == ' ') // Skip the spaces.
        ++i;
      while (j < i || j < n && s[j] != ' ') // Skip the spaces.
        ++j;
      reverse(s, i, j - 1); // Reverse the word.
    }
  }
}
