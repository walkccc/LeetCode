class Solution {
  public boolean checkArray(int[] nums, int k) {
    if (k == 1)
      return true;

    int needDecrease = 0;
    // Store nums[i - k + 1..i] with decreasing nums[i - k + 1].
    Deque<Integer> dq = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      if (i >= k)
        needDecrease -= dq.pollFirst();
      if (nums[i] < needDecrease)
        return false;
      final int decreasedNum = nums[i] - needDecrease;
      dq.offerLast(decreasedNum);
      needDecrease += decreasedNum;
    }

    return dq.getLast() == 0;
  }
}
