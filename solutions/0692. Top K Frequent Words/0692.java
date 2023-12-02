class Solution {
  public List<String> topKFrequent(String[] words, int k) {
    final int n = words.length;
    List<String> ans = new ArrayList<>();
    List<String>[] bucket = new List[n + 1];
    Map<String, Integer> count = new HashMap<>();

    for (final String word : words)
      count.merge(word, 1, Integer::sum);

    for (final String word : count.keySet()) {
      final int freq = count.get(word);
      if (bucket[freq] == null)
        bucket[freq] = new ArrayList<>();
      bucket[freq].add(word);
    }

    for (int freq = n; freq > 0; --freq)
      if (bucket[freq] != null) {
        Collections.sort(bucket[freq]);
        for (final String word : bucket[freq]) {
          ans.add(word);
          if (ans.size() == k)
            return ans;
        }
      }

    throw new IllegalArgumentException();
  }
}
