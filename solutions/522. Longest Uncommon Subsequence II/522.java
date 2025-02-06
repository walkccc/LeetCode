class Solution {
  public int findLUSlength(String[] strs) {
    Set<String> seen = new HashSet<>();
    Set<String> duplicates = new HashSet<>();

    for (final String str : strs)
      if (seen.contains(str))
        duplicates.add(str);
      else
        seen.add(str);

    Arrays.sort(strs, (a, b) -> b.length() - a.length());

    for (int i = 0; i < strs.length; ++i) {
      if (duplicates.contains(strs[i]))
        continue;
      boolean isASubsequence = false;
      for (int j = 0; j < i; ++j)
        isASubsequence |= isSubsequence(strs[i], strs[j]);
      if (!isASubsequence)
        return strs[i].length();
    }

    return -1;
  }

  // Returns true if a is a subsequence of b.
  private boolean isSubsequence(final String a, final String b) {
    int i = 0;
    for (final char c : b.toCharArray())
      if (i < a.length() && c == a.charAt(i))
        ++i;
    return i == a.length();
  }
}
