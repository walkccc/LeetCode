class Solution {
  public long[] mostFrequentIDs(int[] nums, int[] freq) {
    long[] ans = new long[nums.length];
    Map<Integer, Long> numCount = new HashMap<>();      // {num: freq}
    TreeMap<Long, Integer> freqCount = new TreeMap<>(); // {num's freq: freq}

    for (int i = 0; i < nums.length; ++i) {
      final int num = nums[i];
      final int f = freq[i];
      if (numCount.containsKey(num)) {
        final long numFreq = numCount.get(num);
        if (freqCount.merge(numFreq, -1, Integer::sum) == 0)
          freqCount.remove(numFreq);
      }
      final long newFreq = numCount.getOrDefault(num, 0L) + f;
      if (newFreq == 0) {
        numCount.remove(num);
      } else {
        numCount.put(num, newFreq);
        freqCount.merge(newFreq, 1, Integer::sum);
      }
      ans[i] = freqCount.isEmpty() ? 0 : freqCount.lastKey();
    }

    return ans;
  }
}
