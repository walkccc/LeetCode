class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    int[] ans = new int[nums.length - k + 1];
    Deque<Integer> q = new ArrayDeque<>(); // max queue

    for (int i = 0; i < nums.length; ++i) {
      while (!q.isEmpty() && q.peekLast() < nums[i])
        q.pollLast();
      q.offerLast(nums[i]);
      if (i >= k && nums[i - k] == q.peekFirst()) // out of bound
        q.pollFirst();
      if (i >= k - 1)
        ans[i - k + 1] = q.peekFirst();
    }

    return ans;
  }
}
