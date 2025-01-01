class Solution {
  public String largestMerge(String word1, String word2) {
    if (word1.isEmpty())
      return word2;
    if (word2.isEmpty())
      return word1;
    return word1.compareTo(word2) > 0 ? word1.charAt(0) + largestMerge(word1.substring(1), word2)
                                      : word2.charAt(0) + largestMerge(word1, word2.substring(1));
  }
}
