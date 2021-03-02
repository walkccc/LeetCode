class Solution {
  public int shortestDistance(String[] words, String word1, String word2) {
    int ans = words.length;
    int index1 = -1; // words[index1] == word1
    int index2 = -1; // words[index2] == word2

    for (int i = 0; i < words.length; ++i) {
      if (words[i].equals(word1)) {
        index1 = i;
        if (index2 != -1)
          ans = Math.min(ans, index1 - index2);
      }
      if (words[i].equals(word2)) {
        index2 = i;
        if (index1 != -1)
          ans = Math.min(ans, index2 - index1);
      }
    }

    return ans;
  }
}
