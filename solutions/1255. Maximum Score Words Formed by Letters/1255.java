class Solution {
  public int maxScoreWords(String[] words, char[] letters, int[] score) {
    int[] count = new int[26];
    for (final char c : letters)
      ++count[c - 'a'];
    return dfs(words, 0, count, score);
  }

  // max score you can get from words[s:]
  private int dfs(String[] words, int s, int[] count, int[] score) {
    int ans = 0;
    for (int i = s; i < words.length; ++i) {
      final int earned = useWord(words, i, count, score);
      if (earned > 0)
        ans = Math.max(ans, earned + dfs(words, i + 1, count, score));
      unuseWord(words, i, count);
    }
    return ans;
  }

  int useWord(String[] words, int i, int[] count, int[] score) {
    boolean isValid = true;
    int earned = 0;
    for (final char c : words[i].toCharArray()) {
      if (--count[c - 'a'] < 0)
        isValid = false;
      earned += score[c - 'a'];
    }
    return isValid ? earned : -1;
  }

  void unuseWord(String[] words, int i, int[] count) {
    for (final char c : words[i].toCharArray())
      ++count[c - 'a'];
  }
}
