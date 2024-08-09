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
    List<String> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();
    // Words with higher frequency and lower alphabetical order are in the
    // bottom of the heap because we'll pop words with lower frequency and
    // higher alphabetical order if the heap's size > k.
    Queue<T> heap = new PriorityQueue<>(
        (a, b) -> a.freq == b.freq ? b.word.compareTo(a.word) : a.freq - b.freq);

    for (final String word : words)
      count.merge(word, 1, Integer::sum);

    for (final String word : count.keySet()) {
      heap.offer(new T(word, count.get(word)));
      if (heap.size() > k)
        heap.poll();
    }

    while (!heap.isEmpty())
      ans.add(heap.poll().word);

    Collections.reverse(ans);
    return ans;
  }
}
