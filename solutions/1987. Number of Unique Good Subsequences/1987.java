class Solution {
  // Similar to 940. Distinct Subsequences II
  public int numberOfUniqueGoodSubsequences(String binary) {
    final int kMod = 1_000_000_007;
    // endsWith[i] := # of subseqs ends with '0' + i
    int[] endsWith = new int[2];

    for (final char c : binary.toCharArray()) {
      endsWith[c - '0'] = (endsWith[0] + endsWith[1]) % kMod;
      // Don't cound '0' since we want to avoid the leading zeros case.
      // However, we can always count '1'.
      if (c == '1')
        ++endsWith[1];
    }

    // Count '0' in the end.
    return (endsWith[0] + endsWith[1] + (binary.indexOf('0') == -1 ? 0 : 1)) % kMod;
  }
}
