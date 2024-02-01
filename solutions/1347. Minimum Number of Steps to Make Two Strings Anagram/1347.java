class Solution {
  public int minSteps(String s, String t) {
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (final char c : t.toCharArray())
      --count[c - 'a'];

    return Arrays.stream(count).map(Math::abs).sum() / 2;
  }
}
