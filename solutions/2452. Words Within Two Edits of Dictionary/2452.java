class Solution {
  public List<String> twoEditWords(String[] queries, String[] dictionary) {
    List<String> ans = new ArrayList<>();

    for (final String q : queries)
      for (final String word : dictionary)
        if (getDiff(q, word) < 3) {
          ans.add(q);
          break;
        }

    return ans;
  }

  private int getDiff(final String q, final String word) {
    int diff = 0;
    for (int i = 0; i < q.length(); ++i)
      if (q.charAt(i) != word.charAt(i))
        ++diff;
    return diff;
  }
}
