class Solution {
  public int distinctSubseqII(String s) {
    final int kMod = 1_000_000_007;
    // endsIn[i] := the number of subsequence that end in ('a' + i)
    long[] endsIn = new long[26];

    for (final char c : s.toCharArray())
      endsIn[c - 'a'] = (Arrays.stream(endsIn).sum() + 1) % kMod;

    return (int) (Arrays.stream(endsIn).sum() % kMod);
  }
}
