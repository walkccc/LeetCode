class Solution {
  public String rearrangeString(String s, int k) {
    final int n = s.length();
    StringBuilder sb = new StringBuilder();
    int[] count = new int[128];
    int[] valid = new int[128]; // valid[i] := the leftmost index char i can appear

    for (final char c : s.toCharArray())
      ++count[c];

    for (int i = 0; i < n; ++i) {
      final char c = getBestLetter(count, valid, i);
      if (c == '*')
        return "";
      sb.append(c);
      --count[c];
      valid[c] = i + k;
    }

    return sb.toString();
  }

  // return the letter that has most count and also valid
  private char getBestLetter(int[] count, int[] valid, int index) {
    int maxCount = -1;
    char bestLetter = '*';

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c] > 0 && count[c] > maxCount && index >= valid[c]) {
        bestLetter = c;
        maxCount = count[c];
      }

    return bestLetter;
  }
}
