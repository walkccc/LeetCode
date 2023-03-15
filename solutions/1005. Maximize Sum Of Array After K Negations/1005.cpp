class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0 || k == 0)
        break;
      nums[i] = -nums[i];
      --k;
    }

    return accumulate(begin(nums), end(nums), 0) -
           (k % 2) * *min_element(begin(nums), end(nums)) * 2;
  }
};
