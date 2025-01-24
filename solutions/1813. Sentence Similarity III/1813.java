class Solution {
  public boolean areSentencesSimilar(String sentence1, String sentence2) {
    if (sentence1.length() == sentence2.length())
      return sentence1.equals(sentence2);

    String[] words1 = sentence1.split(" ");
    String[] words2 = sentence2.split(" ");
    final int m = words1.length;
    final int n = words2.length;
    if (m > n)
      return areSentencesSimilar(sentence2, sentence1);

    int i = 0; // words1's index
    while (i < m && words1[i].equals(words2[i]))
      ++i;
    while (i < m && words1[i].equals(words2[i + n - m]))
      ++i;

    return i == m;
  }
}
