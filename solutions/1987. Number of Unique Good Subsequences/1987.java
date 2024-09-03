class Solution {
  // Similar to 940. Distinct Subsequences II
  public int numberOfUniqueGoodSubsequences(String binary) {
    final int kMod = 1_000_000_007;
    // endsIn[i] := the number of subsequence that end in ('0' + i)
    int[] endsIn = new int[2];

    for (final char c : binary.toCharArray()) {
      endsIn[c - '0'] = (endsIn[0] + endsIn[1]) % kMod;
      // Don't count '0' since we want to avoid the leading zeros case.
      // However, we can always count '1'.
      if (c == '1')
        ++endsIn[1];
    }

    // Count '0' in the end.
    return (endsIn[0] + endsIn[1] + (binary.indexOf('0') == -1 ? 0 : 1)) % kMod;
  }
}
