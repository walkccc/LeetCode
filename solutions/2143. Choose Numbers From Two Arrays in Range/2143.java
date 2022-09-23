class Solution {
  public int countSubranges(int[] nums1, int[] nums2) {
    final int kMod = 1_000_000_007;
    int ans = 0;
    // {sum, count}, add if choose from nums1, minus if choose from nums2
    Map<Integer, Integer> dp = new HashMap<>();

    for (int i = 0; i < nums1.length; ++i) {
      Map<Integer, Integer> newDp = new HashMap<>();
      // edge case: nums1[i] == nums2[i] == 0, so can't put them in the
      // initializer list
      newDp.merge(nums1[i], 1, Integer::sum);
      newDp.merge(-nums2[i], 1, Integer::sum);

      for (final int prevSum : dp.keySet()) {
        final int count = dp.get(prevSum);
        final int chooseNums1 = prevSum + nums1[i];
        newDp.put(chooseNums1, (newDp.getOrDefault(chooseNums1, 0) + count) % kMod);
        final int chooseNums2 = prevSum - nums2[i];
        newDp.put(chooseNums2, (newDp.getOrDefault(chooseNums2, 0) + count) % kMod);
      }

      dp = newDp;
      if (dp.containsKey(0)) {
        ans += dp.get(0);
        ans %= kMod;
      }
    }

    return ans;
  }
}
