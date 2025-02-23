/**
 * Definition for BigArray.
 * class BigArray {
 *   public BigArray(int[] elements);
 *   public int at(long index);
 *   public long size();
 * }
 */

class Solution {
  public int countBlocks(BigArray nums) {
    return countBlocks(nums, 0, nums.size() - 1, nums.at(0), nums.at(nums.size() - 1));
  }

  // Returns the number of maximal blocks in nums[l..r].
  private int countBlocks(BigArray nums, long l, long r, int leftValue, int rightValue) {
    if (leftValue == rightValue) // nums[l..r] are identical.
      return 1;
    if (l + 1 == r) // nums[l] != nums[r].
      return 2;
    final long m = (l + r) / 2;
    final int midValue = nums.at(m);
    // Substract nums[m], which will be counted twice.
    return countBlocks(nums, l, m, leftValue, midValue) +
        countBlocks(nums, m, r, midValue, rightValue) - 1;
  }
}
