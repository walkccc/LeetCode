/**
 * Definition for BigArray.
 * class BigArray {
 *  public:
 *   BigArray(vector<int> elements);
 *   int at(long long index);
 *   long long size();
 * };
 */

class Solution {
 public:
  int countBlocks(BigArray* nums) {
    return countBlocks(nums, 0, nums->size() - 1, nums->at(0),
                       nums->at(nums->size() - 1));
  }

 private:
  // Returns the number of maximal blocks in nums[l..r].
  int countBlocks(BigArray* nums, long long l, long long r, int leftValue,
                  int rightValue) {
    if (leftValue == rightValue)  // nums[l..r] are identical.
      return 1;
    if (l + 1 == r)  // nums[l] != nums[r].
      return 2;
    const long long m = (l + r) / 2;
    const int midValue = nums->at(m);
    // Substract nums[m], which will be counted twice.
    return countBlocks(nums, l, m, leftValue, midValue) +
           countBlocks(nums, m, r, midValue, rightValue) - 1;
  }
};
