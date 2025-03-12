class Solution {
  public int longestValidSubstring(String word, List<String> forbidden) {
    int ans = 0;
    Set<String> forbiddenSet = new HashSet<>(forbidden);

    // r is the rightmost index to make word[l..r] a valid substring.
    int r = word.length() - 1;
    for (int l = word.length() - 1; l >= 0; --l) {
      for (int end = l; end < Math.min(l + 10, r + 1); ++end)
        if (forbiddenSet.contains(word.substring(l, end + 1))) {
          r = end - 1;
          break;
        }
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
