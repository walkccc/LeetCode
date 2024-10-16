class Solution {
  public int equalCountSubstrings(String s, int count) {
    final int maxUnique = s.chars().mapToObj(c -> (char) c).collect(Collectors.toSet()).size();
    int ans = 0;

    for (int unique = 1; unique <= maxUnique; ++unique) {
      final int windowSize = unique * count;
      int[] lettersCount = new int[26];
      int uniqueCount = 0;
      for (int i = 0; i < s.length(); ++i) {
        if (++lettersCount[s.charAt(i) - 'a'] == count)
          ++uniqueCount;
        if (i >= windowSize && --lettersCount[s.charAt(i - windowSize) - 'a'] == count - 1)
          --uniqueCount;
        ans += uniqueCount == unique ? 1 : 0;
      }
    }

    return ans;
  }
}
