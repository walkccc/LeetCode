class Solution {
  public boolean maxSubstringLength(String s, int k) {
    final int n = s.length();
    int[] first = new int[26];
    int[] last = new int[26];
    // dp[i] := the maximum disjoint special substrings for the first i letters
    int[] dp = new int[n + 1];
    List<Character> seenOrder = new ArrayList<>();

    Arrays.fill(first, n);
    Arrays.fill(last, -1);

    for (int i = 0; i < n; ++i) {
      final char c = s.charAt(i);
      final int a = c - 'a';
      if (first[a] == n) {
        first[a] = i;
        seenOrder.add(c);
      }
      last[a] = i;
    }

    for (final char c : seenOrder) {
      final int a = c - 'a';
      for (int j = first[a]; j < last[a]; ++j) {
        final int b = s.charAt(j) - 'a';
        first[a] = Math.min(first[a], first[b]);
        last[a] = Math.max(last[a], last[b]);
      }
    }

    for (int i = 0; i < n; i++) {
      final char c = s.charAt(i);
      final int a = c - 'a';
      if (last[a] != i || (first[a] == 0 && i == n - 1))
        dp[i + 1] = dp[i];
      else // Start a new special substring.
        dp[i + 1] = Math.max(dp[i], 1 + dp[first[a]]);
    }

    return dp[n] >= k;
  }
}
