class Solution {
  public List<Integer> beautifulIndices(String s, String a, String b, int k) {
    List<Integer> ans = new ArrayList<>();
    List<Integer> indicesA = kmp(s, a);
    List<Integer> indicesB = kmp(s, b);
    int indicesBIndex = 0; // indicesB' index

    for (final int i : indicesA) {
      // The constraint is: |j - i| <= k. So, -k <= j - i <= k. So, move
      // `indicesBIndex` s.t. j - i >= -k, where j := indicesB[indicesBIndex].
      while (indicesBIndex < indicesB.size() && indicesB.get(indicesBIndex) - i < -k)
        ++indicesBIndex;
      if (indicesBIndex < indicesB.size() && indicesB.get(indicesBIndex) - i <= k)
        ans.add(i);
    }

    return ans;
  }

  // Returns the starting indices of all occurrences of the pattern in `s`.
  private List<Integer> kmp(final String s, final String pattern) {
    List<Integer> res = new ArrayList<>();
    int[] lps = getLPS(pattern);
    int i = 0; // s' index
    int j = 0; // pattern's index
    while (i < s.length()) {
      if (s.charAt(i) == pattern.charAt(j)) {
        ++i;
        ++j;
        if (j == pattern.length()) {
          res.add(i - j);
          j = lps[j - 1];
        }
      }
      // Mismatch after j matches.
      else if (j != 0) {
        // Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1];
      } else {
        ++i;
      }
    }
    return res;
  }

  // Returns the lps array, where lps[i] is the length of the longest prefix of
  // pattern[0..i] which is also a suffix of this substring.
  private int[] getLPS(final String pattern) {
    int[] lps = new int[pattern.length()];
    for (int i = 1, j = 0; i < pattern.length(); ++i) {
      while (j > 0 && pattern.charAt(j) != pattern.charAt(i))
        j = lps[j - 1];
      if (pattern.charAt(i) == pattern.charAt(j))
        lps[i] = ++j;
    }
    return lps;
  }
}
