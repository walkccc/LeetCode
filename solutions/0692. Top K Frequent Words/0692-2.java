class T {
  public String word;
  public int freq;

  public T(String word, int freq) {
    this.word = word;
    this.freq = freq;
  }
};

class Solution {
  public List<String> topKFrequent(String[] words, int k) {
    final int n = words.length;

    List<String> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();
    // words w/ higher frequency and lower alphabetical order are in the bottom
    // of the heap, because we'll pop words w/ lower frequency and higher
    // alphabetical order if the heap's size > k

    PriorityQueue<T> pq = new PriorityQueue<>(
        (a, b) -> a.freq == b.freq ? b.word.compareTo(a.word) : a.freq - b.freq);

    for (final String word : words)
      count.put(word, count.getOrDefault(word, 0) + 1);

    for (final String word : count.keySet()) {
      pq.offer(new T(word, count.get(word)));
      if (pq.size() > k)
        pq.poll();
    }

    while (!pq.isEmpty())
      ans.add(pq.poll().word);

    Collections.reverse(ans);
    return ans;
  }
}
