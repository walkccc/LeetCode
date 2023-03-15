class Solution {
  public List<Integer> findSubstring(String s, String[] words) {
    if (s.isEmpty() || words.length == 0)
      return new ArrayList<>();

    final int k = words.length;
    final int n = words[0].length();
    List<Integer> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();

    for (final String word : words)
      count.merge(word, 1, Integer::sum);

    for (int i = 0; i <= s.length() - k * n; ++i) {
      Map<String, Integer> seen = new HashMap<>();
      int j = 0;
      for (; j < k; ++j) {
        final String word = s.substring(i + j * n, i + j * n + n);
        seen.merge(word, 1, Integer::sum);
        if (seen.get(word) > count.getOrDefault(word, 0))
          break;
      }
      if (j == k)
        ans.add(i);
    }

    return ans;
  }
}
