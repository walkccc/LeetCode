class Solution {
  public long countNonDecreasingSubarrays(int[] nums, int k) {
    long ans = 0;
    long cost = 0;
    // Store (number, count) pairs in non-increasing order. The numbers in the
    // queue represent what nums[i..j] look like after adjustments.
    Deque<Pair<Integer, Integer>> dq = new ArrayDeque<>();

    for (int i = nums.length - 1, j = nums.length - 1; i >= 0; --i) {
      final int num = nums[i];
      int count = 1;
      while (!dq.isEmpty() && dq.getLast().getKey() < num) {
        final int nextNum = dq.getLast().getKey();
        final int nextCount = dq.removeLast().getValue();
        count += nextCount;
        // Adjust `nextNum`s to `num`.
        cost += (long) (num - nextNum) * nextCount;
      }
      dq.offerLast(new Pair<>(num, count));
      while (cost > k) {
        final int rightmostNum = dq.getFirst().getKey();
        final int rightmostCount = dq.removeFirst().getValue();
        cost -= (long) (rightmostNum - nums[j--]);
        if (rightmostCount > 1)
          dq.offerFirst(new Pair<>(rightmostNum, rightmostCount - 1));
      }
      ans += j - i + 1;
    }

    return ans;
  }
}
