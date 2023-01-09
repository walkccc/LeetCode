class Solution {
  public String oddString(String[] words) {
    List<Pair<String, Integer>> wordAndHashCodes = getWordAndHashCodes(words);
    Map<Integer, Integer> hashCodeCount = new HashMap<>();

    for (Pair<String, Integer> wordAndHashCode : wordAndHashCodes)
      hashCodeCount.merge(wordAndHashCode.getValue(), 1, Integer::sum);

    for (Pair<String, Integer> wordAndHashCode : wordAndHashCodes)
      if (hashCodeCount.get(wordAndHashCode.getValue()) == 1)
        return wordAndHashCode.getKey();

    throw new IllegalArgumentException();
  }

  // Returns pairs of word and its corresponding hash code.
  private List<Pair<String, Integer>> getWordAndHashCodes(String[] words) {
    List<Pair<String, Integer>> wordAndHashCodes = new ArrayList<>();
    for (final String word : words)
      wordAndHashCodes.add(new Pair<>(word, getDiffStr(word).hashCode()));
    return wordAndHashCodes;
  }

  // Returns difference string of `s`.
  // E.g., getDiffStr("adc") -> "3#-1#"
  private String getDiffStr(final String s) {
    StringBuilder sb = new StringBuilder();
    for (int i = 1; i < s.length(); ++i)
      sb.append(s.charAt(i) - s.charAt(i - 1)).append("#");
    return sb.toString();
  }
}
