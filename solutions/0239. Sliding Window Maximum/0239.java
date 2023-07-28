class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    int[] ans = new int[nums.length - k + 1];
    Deque<Integer> dq = new ArrayDeque<>(); // max queue

    for (int i = 0; i < nums.length; ++i) {
      while (!dq.isEmpty() && dq.peekLast() < nums[i])
        dq.pollLast();
      dq.offerLast(nums[i]);
      if (i >= k && nums[i - k] == dq.peekFirst()) // out of bound
        dq.pollFirst();
      if (i >= k - 1)
        ans[i - k + 1] = dq.peekFirst();
    }

    return ans;
  }
}
