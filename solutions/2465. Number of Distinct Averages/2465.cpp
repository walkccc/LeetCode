class Solution {
 public:
  int distinctAverages(vector<int>& nums) {
    const int n = nums.size();
    unordered_set<int> sums;

    sort(begin(nums), end(nums));

    for (int i = 0; i < n / 2; ++i)
      sums.insert(nums[i] + nums[n - i - 1]);

    return sums.size();
  }
};
