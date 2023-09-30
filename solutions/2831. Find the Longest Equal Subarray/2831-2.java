class Solution {
  public int longestEqualSubarray(List<Integer> nums, int k) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    // l and r track max window instead of valid window.
    for (int l = 0, r = 0; r < nums.size(); ++r) {
      ans = Math.max(ans, count.merge(nums.get(r), 1, Integer::sum));
      if (r - l + 1 - k > ans)
        count.merge(nums.get(l++), -1, Integer::sum);
    }

    return ans;
  }
}
