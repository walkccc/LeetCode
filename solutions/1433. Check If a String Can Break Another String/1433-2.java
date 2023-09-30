class Solution {
  public boolean checkIfCanBreak(String s1, String s2) {
    int[] count = new int[26];

    for (final char c : s1.toCharArray())
      ++count[c - 'a'];

    for (final char c : s2.toCharArray())
      --count[c - 'a'];

    for (int i = 1; i < 26; ++i)
      count[i] += count[i - 1];

    return Arrays.stream(count).allMatch(c -> c <= 0) || Arrays.stream(count).allMatch(c -> c >= 0);
  }
}
