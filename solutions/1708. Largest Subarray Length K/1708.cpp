class Solution {
 public:
  vector<int> largestSubarray(vector<int>& nums, int k) {
    const auto it = max_element(nums.begin(), nums.end() - k + 1);
    return std::vector<int>(it, it + k);
  }
};
