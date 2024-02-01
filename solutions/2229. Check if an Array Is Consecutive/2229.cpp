class Solution {
 public:
  bool isConsecutive(vector<int>& nums) {
    const int n = nums.size();
    const int max = ranges::max(nums);
    const int min = ranges::min(nums);
    return max - min + 1 == n &&
           unordered_set<int>{nums.begin(), nums.end()}.size() == n;
  }
};
