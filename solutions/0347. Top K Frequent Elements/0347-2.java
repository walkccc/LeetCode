class Solution {
  public int[] topKFrequent(int[] nums, int k) {
    final int n = nums.length;

    List<Integer> ans = new ArrayList<>();
    List<Integer>[] bucket = new List[n + 1];
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.put(num, count.getOrDefault(num, 0) + 1);

    for (final int num : count.keySet()) {
      final int freq = count.get(num);
      if (bucket[freq] == null)
        bucket[freq] = new ArrayList<>();
      bucket[freq].add(num);
    }

    for (int freq = n; freq > 0; --freq) {
      if (bucket[freq] != null)
        ans.addAll(bucket[freq]);
      if (ans.size() == k)
        return ans.stream().mapToInt(i -> i).toArray();
    }

    throw new IllegalArgumentException();
  }
}
