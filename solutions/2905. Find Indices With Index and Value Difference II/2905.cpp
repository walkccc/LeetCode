class Solution {
 public:
  vector<int> findIndices(vector<int>& nums, int indexDifference,
                          int valueDifference) {
    // nums[minIndex] := min num with enough index diff from current num
    int minIndex = 0;
    // nums[maxIndex] := max num with enough index diff from current num
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
