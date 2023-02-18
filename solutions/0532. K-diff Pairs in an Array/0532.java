class Solution {
  public int findPairs(int[] nums, int k) {
    int ans = 0;
    Map<Integer, Integer> numToIndex = new HashMap<>();

    for (int i = 0; i < nums.length; ++i)
      numToIndex.put(nums[i], i);

    for (int i = 0; i < nums.length; ++i) {
      final int target = nums[i] + k;
      if (numToIndex.containsKey(target) && numToIndex.get(target) != i) {
        ++ans;
        numToIndex.remove(target);
      }
    }

    return ans;
  }
}
