class Solution {
 public:
  int maxSum(vector<int>& nums) {
    const int mx = ranges::max(nums);
    if (mx <= 0)
      return mx;
    unordered_set<int> numsSet(nums.begin(), nums.end());
    return accumulate(numsSet.begin(), numsSet.end(), 0,
                      [](int acc, int num) { return acc + max(0, num); });
  }
};
