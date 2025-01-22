class Solution {
  public long[] countKConstraintSubstrings(String s, int k, int[][] queries) {
    final int n = s.length();
    long[] ans = new long[queries.length];
    int[] count = new int[2];
    // leftToRight[l] : = the maximum right index r s.t.s[l..r] is valid
    int[] leftToRight = new int[n];
    // rightToLeft[r] := the minimum left index l s.t. s[l..r] is valid
    int[] rightToLeft = new int[n];
    // prefix[i] := the number of valid substrings ending in [0..i - 1].
    long[] prefix = new long[n + 1];

    for (int l = 0, r = 0; r < n; ++r) {
      ++count[s.charAt(r) - '0'];
      while (count[0] > k && count[1] > k)
        --count[s.charAt(l++) - '0'];
      rightToLeft[r] = l;
    }

    Arrays.fill(count, 0);

    for (int l = n - 1, r = n - 1; l >= 0; --l) {
      ++count[s.charAt(l) - '0'];
      while (count[0] > k && count[1] > k)
        --count[s.charAt(r--) - '0'];
      leftToRight[l] = r;
    }

    for (int r = 0; r < n; ++r)
      prefix[r + 1] = prefix[r] + r - rightToLeft[r] + 1;

    for (int i = 0; i < queries.length; ++i) {
      final int l = queries[i][0];
      final int r = queries[i][1];
      long numValidSubstrings = 0;
      if (r > leftToRight[l]) {
        // If r is beyond leftToRight[l], compute the number of valid substrings
        // from l to leftToRight[l] and add the number of valid substrings
        // ending in [leftToRight[l] + 1..r].
        //
        // prefix[r + 1] := the number of valid substrings ending in [0..r].
        // prefix[leftToRight[l] + 1] := the number of valid substrings ending
        // in [0..leftToRight].
        // => prefix[r + 1] - prefix[leftToRight[l] + 1] := the number of valid
        // substrings ending in [leftToRight[l] + 1..r].
        final int sz = leftToRight[l] - l + 1;
        numValidSubstrings = (sz * (sz + 1)) / 2 + (prefix[r + 1] - prefix[leftToRight[l] + 1]);
      } else {
        final int sz = r - l + 1;
        numValidSubstrings = (sz * (long) (sz + 1)) / 2;
      }
      ans[i] = numValidSubstrings;
    }

    return ans;
  }
}
