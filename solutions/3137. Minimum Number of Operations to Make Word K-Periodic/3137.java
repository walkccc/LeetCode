class Solution {
  public int minimumOperationsToMakeKPeriodic(String word, int k) {
    Map<String, Integer> count = new HashMap<>();

    for (int i = 0; i < word.length(); i += k)
      count.merge(word.substring(i, i + k), 1, Integer::sum);

    final int maxFreq = count.values().stream().max(Integer::compare).orElse(0);
    return word.length() / k - maxFreq;
  }
}
