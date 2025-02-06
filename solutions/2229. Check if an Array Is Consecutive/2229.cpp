class Solution {
 public:
  bool isConsecutive(vector<int>& nums) {
    const int n = nums.size();
    const int mx = ranges::max(nums);
    const int mn = ranges::min(nums);
    return mx - mn + 1 == n &&
           unordered_set<int>{nums.begin(), nums.end()}.size() == n;
  }
};
