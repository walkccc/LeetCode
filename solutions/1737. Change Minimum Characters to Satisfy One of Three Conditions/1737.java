class Solution {
  public int minCharacters(String a, String b) {
    final int m = a.length();
    final int n = b.length();
    int[] countA = new int[26];
    int[] countB = new int[26];

    for (final char c : a.toCharArray())
      ++countA[c - 'a'];

    for (final char c : b.toCharArray())
      ++countB[c - 'a'];

    int ans = Integer.MAX_VALUE;
    int prevA = 0; // the number of characters in a <= c
    int prevB = 0; // the number of characters in b <= c

    for (char c = 'a'; c <= 'z'; ++c) {
      // the condition 3
      ans = Math.min(ans, m + n - countA[c - 'a'] - countB[c - 'a']);
      // the conditions 1 and 2
      if (c > 'a')
        ans = Math.min(ans, Math.min(m - prevA + prevB, n - prevB + prevA));
      prevA += countA[c - 'a'];
      prevB += countB[c - 'a'];
    }

    return ans;
  }
}
