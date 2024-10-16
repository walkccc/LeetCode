class Solution {
  public int[] validSequence(String word1, String word2) {
    int[] ans = new int[word2.length()];
    // last[j] := the index i of the last occurrence in word1, where
    // word1[i] == word2[j]
    int[] last = new int[word2.length()];
    Arrays.fill(last, -1);

    int i = word1.length() - 1;
    int j = word2.length() - 1;
    while (i >= 0 && j >= 0) {
      if (word1.charAt(i) == word2.charAt(j))
        last[j--] = i;
      --i;
    }

    boolean canSkip = true;
    j = 0;
    for (i = 0; i < word1.length(); ++i) {
      if (j == word2.length())
        break;
      if (word1.charAt(i) == word2.charAt(j)) {
        ans[j++] = i;
      } else if (canSkip && (j == word2.length() - 1 || i < last[j + 1])) {
        canSkip = false;
        ans[j++] = i;
      }
    }

    return j == word2.length() ? ans : new int[0];
  }
}
