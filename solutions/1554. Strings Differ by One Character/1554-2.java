class Solution {
  public boolean differByOne(String[] dict) {
    final int m = dict[0].length();
    int[] wordToHash = new int[dict.length];

    for (int i = 0; i < dict.length; ++i)
      wordToHash[i] = getHash(dict[i]);

    // Compute the hash without each letter.
    // e.g. hash of "abc" = 26^2 * 'a' + 26 * 'b' + 'c'
    //   newHash of "a*c" = hash - 26 * 'b'
    int coefficient = 1;
    for (int j = m - 1; j >= 0; --j) {
      Map<Integer, List<Integer>> newHashToIndices = new HashMap<>();
      for (int i = 0; i < dict.length; ++i) {
        final int newHash =
            (int) ((wordToHash[i] - (long) coefficient * val(dict[i].charAt(j)) % kHash + kHash) %
                   kHash);
        if (newHashToIndices.containsKey(newHash)) {
          for (final int index : newHashToIndices.get(newHash)) {
            if (dict[i].substring(0, j).equals(dict[index].substring(0, j)) &&
                dict[i].substring(j + 1).equals(dict[index].substring(j + 1))) {
              return true;
            }
          }
        }
        newHashToIndices.putIfAbsent(newHash, new ArrayList<>());
        newHashToIndices.get(newHash).add(i);
      }
      coefficient = (int) (coefficient * kBase % kHash);
    }

    return false;
  }

  private static final long kBase = 26;
  private static final int kHash = 1_000_000_007;

  private static int val(char c) {
    return c - 'a';
  }

  // Returns the hash of `s`. Assume the length of `s` is m.
  // e.g. getHash(s) = 26^(m - 1) * s[0] + 26^(m - 2) * s[1] + ... + s[m - 1].
  private int getHash(String s) {
    int hash = 0;
    for (final char c : s.toCharArray()) {
      hash = (int) ((hash * kBase + val(c)) % kHash);
    }
    return hash;
  }
}
