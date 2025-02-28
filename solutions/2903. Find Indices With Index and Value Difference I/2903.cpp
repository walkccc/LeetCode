class Solution {
 public:
  vector<int> findIndices(vector<int>& nums, int indexDifference,
                          int valueDifference) {
    // nums[minIndex] := the minimum number with enough index different from the
    // current number
    int minIndex = 0;
    // nums[maxIndex] := the maximum number with enough index different from the
    // current number
    int maxIndex = 0;

    for (int i = indexDifference; i < nums.size(); ++i) {
      if (nums[i - indexDifference] < nums[minIndex])
        minIndex = i - indexDifference;
      if (nums[i - indexDifference] > nums[maxIndex])
        maxIndex = i - indexDifference;
      if (nums[i] - nums[minIndex] >= valueDifference)
        return {i, minIndex};
      if (nums[maxIndex] - nums[i] >= valueDifference)
        return {i, maxIndex};
    }

    return {-1, -1};
  }
};
