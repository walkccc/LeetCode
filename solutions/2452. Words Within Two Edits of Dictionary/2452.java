class Solution {
  public List<String> twoEditWords(String[] queries, String[] dictionary) {
    List<String> ans = new ArrayList<>();

    for (final String query : queries)
      for (final String word : dictionary)
        if (getDiff(query, word) < 3) {
          ans.add(query);
          break;
        }

    return ans;
  }

  private int getDiff(final String query, final String word) {
    int diff = 0;
    for (int i = 0; i < query.length(); ++i)
      if (query.charAt(i) != word.charAt(i))
        ++diff;
    return diff;
  }
}
