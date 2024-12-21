class Solution {
  public String[] uncommonFromSentences(String A, String B) {
    List<String> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();

    for (final String word : (A + ' ' + B).split(" "))
      count.merge(word, 1, Integer::sum);

    for (final String word : count.keySet())
      if (count.get(word) == 1)
        ans.add(word);

    return ans.toArray(new String[0]);
  }
}
