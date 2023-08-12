class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0 || k == 0)
        break;
      nums[i] = -nums[i];
      --k;
    }

    return accumulate(nums.begin(), nums.end(), 0) -
           (k % 2) * *min_element(nums.begin(), nums.end()) * 2;
  }
};
