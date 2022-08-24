class Solution {
  public int shortestWordDistance(String[] words, String word1, String word2) {
    final boolean isSame = word1.equals(word2);
    int ans = Integer.MAX_VALUE;
    int index1 = words.length;  // if word1 == word2, index1 is the newest index
    int index2 = -words.length; // if word1 == word2, index2 is the previous index

    for (int i = 0; i < words.length; ++i) {
      if (words[i].equals(word1)) {
        if (isSame)
          index2 = index1;
        index1 = i;
      } else if (words[i].equals(word2)) {
        index2 = i;
      }
      ans = Math.min(ans, Math.abs(index1 - index2));
    }

    return ans;
  }
}
