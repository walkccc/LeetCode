class Solution {
  public List<String> commonChars(String[] words) {
    List<String> ans = new ArrayList<>();
    int[] commonCount = new int[26];
    Arrays.fill(commonCount, Integer.MAX_VALUE);

    for (final String word : words) {
      int[] count = new int[26];
      for (final char c : word.toCharArray())
        ++count[c - 'a'];
      for (int i = 0; i < 26; ++i)
        commonCount[i] = Math.min(commonCount[i], count[i]);
    }

    for (char c = 'a'; c <= 'z'; ++c)
      for (int i = 0; i < commonCount[c - 'a']; ++i)
        ans.add(String.valueOf(c));

    return ans;
  }
}
