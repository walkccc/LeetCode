class T {
  public int num;
  public int freq;

  public T(int num, int freq) {
    this.num = num;
    this.freq = freq;
  }
}

class Solution {
  public int[] topKFrequent(int[] nums, int k) {
    final int n = nums.length;

    int[] ans = new int[k];
    Map<Integer, Integer> count = new HashMap<>();
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> a.freq - b.freq);

    for (final int num : nums)
      count.put(num, count.getOrDefault(num, 0) + 1);

    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final int num = entry.getKey();
      final int freq = entry.getValue();
      pq.offer(new T(num, freq));
      if (pq.size() > k)
        pq.poll();
    }

    for (int i = 0; i < k; ++i)
      ans[i] = pq.poll().num;

    return ans;
  }
}
