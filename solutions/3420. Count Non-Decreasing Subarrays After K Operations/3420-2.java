class Solution {
  public long countNonDecreasingSubarrays(int[] nums, int k) {
    long ans = 0;
    long cost = 0;
    // Store indices of `nums` with `nums[i]` in non-increasing order.
    Deque<Integer> dq = new ArrayDeque<>();

    for (int i = nums.length - 1, j = nums.length - 1; i >= 0; --i) {
      final int num = nums[i];
      while (!dq.isEmpty() && nums[dq.peekLast()] < num) {
        final int l = dq.pollLast();
        final int r = dq.isEmpty() ? j + 1 : dq.peekLast();
        // Adjust `nums[l]` to `num`.
        cost += (long) (r - l) * (num - nums[l]);
      }
      dq.offerLast(i);
      while (cost > k) { // Remove the rightmost number.
        cost -= nums[dq.peekFirst()] - nums[j];
        if (dq.peekFirst() == j)
          dq.pollFirst();
        --j;
      }
      ans += j - i + 1;
    }

    return ans;
  }
}
