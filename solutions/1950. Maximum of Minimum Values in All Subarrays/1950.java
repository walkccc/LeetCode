class Solution {
  // Similar to 1950. Maximum of Minimum Values in All Subarrays
  public int[] findMaximums(int[] nums) {
    final int n = nums.length;
    int[] ans = new int[n];
    // prevMin[i] := the index k s.t.
    // nums[k] is the previous minimum in nums[0..n)
    int[] prevMin = new int[n];
    // nextMin[i] := the index k s.t.
    // nums[k] is the next minimum innums[i + 1..n)
    int[] nextMin = new int[n];
    Deque<Integer> stack = new ArrayDeque<>();

    Arrays.fill(prevMin, -1);
    Arrays.fill(nextMin, n);

    for (int i = 0; i < n; ++i) {
      while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
        final int index = stack.pop();
        nextMin[index] = i;
      }
      if (!stack.isEmpty())
        prevMin[i] = stack.peek();
      stack.push(i);
    }

    // For each nums[i], let l = nextMin[i] + 1 and r = nextMin[i] - 1.
    // nums[i] is the minimun in nums[l..r].
    // So, the ans[r - l + 1] will be at least nums[i].
    for (int i = 0; i < n; ++i) {
      final int sz = nextMin[i] - prevMin[i] - 1;
      ans[sz - 1] = Math.max(ans[sz - 1], nums[i]);
    }

    // ans[i] should always >= ans[i + 1..n).
    for (int i = n - 2; i >= 0; --i)
      ans[i] = Math.max(ans[i], ans[i + 1]);

    return ans;
  }
}
