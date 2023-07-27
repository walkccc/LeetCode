class Solution {
 public:
  bool isConsecutive(vector<int>& nums) {
    const int n = nums.size();
    const int max = *max_element(nums.begin(), nums.end());
    const int min = *min_element(nums.begin(), nums.end());
    return max - min + 1 == n &&
           unordered_set<int>{nums.begin(), nums.end()}.size() == n;
  }
};
