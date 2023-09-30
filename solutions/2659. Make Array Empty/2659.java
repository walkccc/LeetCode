class Solution {
  public long countOperationsToEmptyArray(int[] nums) {
    final int n = nums.length;
    long ans = n;
    Map<Integer, Integer> numToIndex = new HashMap<>();

    for (int i = 0; i < n; ++i)
      numToIndex.put(nums[i], i);

    Arrays.sort(nums);

    for (int i = 1; i < n; ++i)
      // On i-th step we've already removed i - 1 smallest nums and can ignore
      // them. If an element nums[i] has smaller index in origin array than
      // nums[i - 1], we should rotate whole left array n - i times to set
      // nums[i] element on the 1st position.
      if (numToIndex.get(nums[i]) < numToIndex.get(nums[i - 1]))
        ans += n - i;

    return ans;
  }
}
