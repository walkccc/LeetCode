class Solution {
  public String[] uncommonFromSentences(String A, String B) {
    List<String> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();

    for (final String word : (A + ' ' + B).split(" "))
      count.put(word, count.getOrDefault(word, 0) + 1);

    for (final String word : count.keySet())
      if (count.get(word) == 1)
        ans.add(word);

    return ans.toArray(new String[0]);
  }
}
