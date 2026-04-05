class Solution {
  public String findCommonResponse(List<List<String>> responses) {
    String ans = "";
    Map<String, Integer> count = new HashMap<>();
    int maxFreq = 0;

    for (List<String> response : responses)
      for (final String r : new HashSet<>(response))
        count.merge(r, 1, Integer::sum);

    for (final int freq : count.values())
      maxFreq = Math.max(maxFreq, freq);

    for (Map.Entry<String, Integer> entry : count.entrySet()) {
      final String response = entry.getKey();
      final int freq = entry.getValue();
      if (freq == maxFreq && (ans.isEmpty() || response.compareTo(ans) < 0))
        ans = response;
    }

    return ans;
  }
}
