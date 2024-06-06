class Solution {
  public boolean circularArrayLoop(int[] nums) {
    if (nums.length < 2)
      return false;

    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] == 0)
        continue;
      int slow = i;
      int fast = advance(nums, slow);
      while (nums[i] * nums[fast] > 0 && nums[i] * nums[advance(nums, fast)] > 0) {
        if (slow == fast) {
          if (slow == advance(nums, slow))
            break;
          return true;
        }
        slow = advance(nums, slow);
        fast = advance(nums, advance(nums, fast));
      }

      slow = i;
      final int sign = nums[i];
      while (sign * nums[slow] > 0) {
        final int next = advance(nums, slow);
        nums[slow] = 0;
        slow = next;
      }
    }

    return false;
  }

  private int advance(int[] nums, int i) {
    final int n = nums.length;
    final int val = (i + nums[i]) % n;
    return i + nums[i] >= 0 ? val : n + val;
  }
}
