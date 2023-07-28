class Solution {
  public boolean checkArray(int[] nums, int k) {
    if (k == 1)
      return true;

    int needDecrease = 0;
    // Store nums[i - k + 1..i] with decreasing nums[i - k + 1].
    Deque<Integer> q = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      if (i >= k)
        needDecrease -= q.pollFirst();
      if (nums[i] < needDecrease)
        return false;
      final int decreasedNum = nums[i] - needDecrease;
      q.offerLast(decreasedNum);
      needDecrease += decreasedNum;
    }

    return q.getLast() == 0;
  }
}
