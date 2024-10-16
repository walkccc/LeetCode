class Solution {
  public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
    // nums[minIndex] := the minimum number with enough index different from the
    // current number
    int minIndex = 0;
    // nums[maxIndex] := the maximum number with enough index different from the
    // current number
    int maxIndex = 0;

    for (int i = indexDifference; i < nums.length; ++i) {
      if (nums[i - indexDifference] < nums[minIndex])
        minIndex = i - indexDifference;
      if (nums[i - indexDifference] > nums[maxIndex])
        maxIndex = i - indexDifference;
      if (nums[i] - nums[minIndex] >= valueDifference)
        return new int[] {i, minIndex};
      if (nums[maxIndex] - nums[i] >= valueDifference)
        return new int[] {i, maxIndex};
    }

    return new int[] {-1, -1};
  }
}
