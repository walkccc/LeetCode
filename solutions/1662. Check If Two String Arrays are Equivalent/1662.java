class Solution {
  public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
    int i = 0; // word1's index
    int j = 0; // word2's index
    int a = 0; // word1[i]'s index
    int b = 0; // word2[j]'s index

    while (i < word1.length && j < word2.length) {
      if (word1[i].charAt(a) != word2[j].charAt(b))
        return false;
      if (++a == word1[i].length()) {
        ++i;
        a = 0;
      }
      if (++b == word2[j].length()) {
        ++j;
        b = 0;
      }
    }

    return i == word1.length && j == word2.length;
  }
}
