class Solution {
  public int minCharacters(String a, String b) {
    final int m = a.length();
    final int n = b.length();
    int[] countA = new int[128];
    int[] countB = new int[128];

    for (final char c : a.toCharArray())
      ++countA[c];

    for (final char c : b.toCharArray())
      ++countB[c];

    int ans = Integer.MAX_VALUE;
    int prevA = 0; // # of chars in a <= c
    int prevB = 0; // # of chars in b <= c

    for (char c = 'a'; c <= 'z'; ++c) {
      // condition 3
      ans = Math.min(ans, m + n - countA[c] - countB[c]);
      // condition 1 and 2
      if (c > 'a')
        ans = Math.min(ans, Math.min(m - prevA + prevB, n - prevB + prevA));
      prevA += countA[c];
      prevB += countB[c];
    }

    return ans;
  }
}
