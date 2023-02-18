class Solution {
  public boolean checkIfPangram(String sentence) {
    int seen = 0;

    for (final char c : sentence.toCharArray())
      seen |= 1 << c - 'a';

    return seen == (1 << 26) - 1;
  }
}
