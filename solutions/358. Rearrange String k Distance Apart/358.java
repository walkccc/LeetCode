class Solution {
  public String rearrangeString(String s, int k) {
    final int n = s.length();
    StringBuilder sb = new StringBuilder();
    int[] count = new int[26];
    // valid[i] := the leftmost index character i can appear
    int[] valid = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (int i = 0; i < n; ++i) {
      final char c = getBestLetter(count, valid, i);
      if (c == '*')
        return "";
      sb.append(c);
      --count[c - 'a'];
      valid[c - 'a'] = i + k;
    }

    return sb.toString();
  }

  // Returns the valid letter that has the most count.
  private char getBestLetter(int[] count, int[] valid, int index) {
    int maxCount = -1;
    char bestLetter = '*';

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c - 'a'] > 0 && count[c - 'a'] > maxCount && index >= valid[c - 'a']) {
        bestLetter = c;
        maxCount = count[c - 'a'];
      }

    return bestLetter;
  }
}
