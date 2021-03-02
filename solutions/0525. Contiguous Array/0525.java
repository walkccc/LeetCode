class Solution {
  public int findMaxLength(int[] nums) {
    int ans = 0;
    int prefix = 0;
    Map<Integer, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i] == 1 ? 1 : -1;
      if (prefixToIndex.containsKey(prefix))
        ans = Math.max(ans, i - prefixToIndex.get(prefix));
      else
        prefixToIndex.put(prefix, i);
    }

    return ans;
  }
}
