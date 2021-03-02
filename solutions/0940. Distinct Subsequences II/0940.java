class Solution {
  public int distinctSubseqII(String S) {
    final long kMod = (long) 1e9 + 7;

    // endsWith[i] := # of subseqs ends with 'a' + i
    long[] endsWith = new long[26];

    for (final char c : S.toCharArray())
      endsWith[c - 'a'] = (Arrays.stream(endsWith).sum() + 1) % kMod;

    return (int) (Arrays.stream(endsWith).sum() % kMod);
  }
}
