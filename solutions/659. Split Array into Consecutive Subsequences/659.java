class Solution {
  public boolean isPossible(int[] nums) {
    Map<Integer, Integer> count = new HashMap<>();
    List<Integer> starts = new ArrayList<>(); // the start indices of each subsequence
    List<Integer> ends = new ArrayList<>();   // the end indices of each subsequence

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (int i = 0; i < nums.length; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      final int num = nums[i];
      final int currCount = count.get(num);
      final int prevCount = count.getOrDefault(num - 1, 0);
      final int nextCount = count.getOrDefault(num + 1, 0);
      for (int j = 0; j < currCount - prevCount; ++j)
        starts.add(num);
      for (int j = 0; j < currCount - nextCount; ++j)
        ends.add(num);
    }

    for (int i = 0; i < starts.size(); ++i)
      if (ends.get(i) - starts.get(i) < 2)
        return false;

    return true;
  }
}
