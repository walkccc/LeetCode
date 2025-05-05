class Solution {
  public List<String> wordsAbbreviation(List<String> words) {
    final int n = words.size();
    List<String> ans = new ArrayList<>();
    // prefix[i] := ans[i] takes words[i][0..prefix[i]]
    int[] prefix = new int[n];

    for (int i = 0; i < n; ++i)
      ans.add(getAbbrev(words.get(i), 0));

    for (int i = 0; i < n; ++i)
      while (true) {
        List<Integer> dupeIndices = new ArrayList<>();
        for (int j = i + 1; j < n; ++j)
          if (ans.get(i).equals(ans.get(j)))
            dupeIndices.add(j);
        if (dupeIndices.isEmpty())
          break;
        dupeIndices.add(i);
        for (final int dupeIndex : dupeIndices)
          ans.set(dupeIndex, getAbbrev(words.get(dupeIndex), ++prefix[dupeIndex]));
      }

    return ans;
  }

  private String getAbbrev(final String s, int prefixIndex) {
    final int n = s.length();
    final int num = n - (prefixIndex + 1) - 1;
    final int numLength = num < 10 ? 1 : num < 100 ? 2 : 3;
    final int abbrevLength = (prefixIndex + 1) + numLength + 1;
    if (abbrevLength >= n)
      return s;
    return s.substring(0, prefixIndex + 1) + num + s.charAt(n - 1);
  }
}
