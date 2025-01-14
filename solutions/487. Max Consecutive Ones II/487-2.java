class Solution {
  public int findMaxConsecutiveOnes(int[] nums) {
    final int maxZeros = 1;
    int ans = 0;
    // Store indices of zero.
    Queue<Integer> q = new ArrayDeque<>();

    for (int l = 0, r = 0; r < nums.length; ++r) {
      if (nums[r] == 0)
        q.offer(r);
      if (q.size() > maxZeros)
        l = q.poll() + 1;
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
