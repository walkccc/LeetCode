class Solution {
  public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
    // nums[minIndex] := min num with enough index diff from current num
    int minIndex = 0;
    // nums[maxIndex] := max num with enough index diff from current num
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
