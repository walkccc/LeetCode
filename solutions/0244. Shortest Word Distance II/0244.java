class WordDistance {
  public WordDistance(String[] words) {
    for (int i = 0; i < words.length; ++i) {
      wordToIndices.putIfAbsent(words[i], new ArrayList<>());
      wordToIndices.get(words[i]).add(i);
    }
  }

  public int shortest(String word1, String word2) {
    int ans = Integer.MAX_VALUE;
    final List<Integer> indices1 = wordToIndices.get(word1);
    final List<Integer> indices2 = wordToIndices.get(word2);

    for (int i = 0, j = 0; i < indices1.size() && j < indices2.size();) {
      ans = Math.min(ans, Math.abs(indices1.get(i) - indices2.get(j)));
      if (indices1.get(i) < indices2.get(j))
        ++i;
      else
        ++j;
    }

    return ans;
  }

  private Map<String, List<Integer>> wordToIndices = new HashMap<>();
}
