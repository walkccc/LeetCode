class Solution {
  public long shiftDistance(String s, String t, int[] nextCost, int[] previousCost) {
    long ans = 0;
    // prev[i][j]: the prev cost to shift from ('a' + i) to ('a' + j)
    long[][] prev = new long[26][26];
    // next[i][j]: the next cost to shift from ('a' + i) to ('a' + j)
    long[][] next = new long[26][26];

    for (int i = 0; i < 26; ++i) {
      long cost = 0;
      for (int j = 0; j < 26; ++j) {
        next[i][(i + j) % 26] = cost;
        cost += nextCost[(i + j) % 26];
      }
    }

    for (int i = 0; i < 26; ++i) {
      long cost = 0;
      for (int j = 0; j < 26; ++j) {
        prev[i][(i - j + 26) % 26] = cost;
        cost += previousCost[(i - j + 26) % 26];
      }
    }

    for (int i = 0; i < s.length(); ++i) {
      final int a = s.charAt(i) - 'a';
      final int b = t.charAt(i) - 'a';
      ans += Math.min(next[a][b], prev[a][b]);
    }

    return ans;
  }
}
