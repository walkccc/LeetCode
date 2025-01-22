class Solution {
  public int maxSelectedElements(int[] nums) {
    int ans = 0;
    // {num: the length of the longest consecutive elements ending in num}
    HashMap<Integer, Integer> dp = new HashMap<>();

    Arrays.sort(nums);

    for (final int num : nums) {
      dp.put(num + 1, dp.getOrDefault(num, 0) + 1);
      dp.put(num, dp.getOrDefault(num - 1, 0) + 1);
      ans = Math.max(ans, Math.max(dp.get(num), dp.get(num + 1)));
    }

    return ans;
  }
}
