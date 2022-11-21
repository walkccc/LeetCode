class Solution {
  public int maxEqualFreq(int[] nums) {
    int ans = 0;
    int maxFreq = 0;
    Map<Integer, Integer> count = new HashMap<>();
    Map<Integer, Integer> freq = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      int currentFreq = count.getOrDefault(nums[i], 0);
      freq.put(currentFreq, freq.getOrDefault(currentFreq, 0) - 1);
      int updatedFreq = currentFreq + 1;
      count.put(nums[i], updatedFreq);
      freq.put(updatedFreq, freq.getOrDefault(updatedFreq, 0) + 1);
      maxFreq = Math.max(maxFreq, updatedFreq);
      if (maxFreq == 1 || maxFreq * freq.get(maxFreq) == i ||
          (maxFreq - 1) * (freq.get(maxFreq - 1) + 1) == i)
        ans = i + 1;
    }

    return ans;
  }
}
