class Solution {
  public boolean checkAlmostEquivalent(String word1, String word2) {
    int[] count = new int[26];

    for (final char c : word1.toCharArray())
      ++count[c - 'a'];

    for (final char c : word2.toCharArray())
      --count[c - 'a'];

    return Arrays.stream(count).allMatch(freq -> Math.abs(freq) <= 3);
  }
}
