class Solution {
  public String mostCommonWord(String paragraph, String[] banned) {
    Pair<String, Integer> ans = new Pair<>("", 0);
    Set<String> bannedSet = new HashSet<>(Arrays.asList(banned));
    Map<String, Integer> count = new HashMap<>();
    String[] words = paragraph.replaceAll("\\W+", " ").toLowerCase().split("\\s+");

    for (final String word : words)
      if (!bannedSet.contains(word))
        if (count.merge(word, 1, Integer::sum) > ans.getValue())
          ans = new Pair<>(word, count.get(word));

    return ans.getKey();
  }
}
