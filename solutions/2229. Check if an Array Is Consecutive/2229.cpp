class Solution {
 public:
  bool isConsecutive(vector<int>& nums) {
    const int n = nums.size();
    const int max = *max_element(begin(nums), end(nums));
    const int min = *min_element(begin(nums), end(nums));
    return max - min + 1 == n &&
           unordered_set<int>{begin(nums), end(nums)}.size() == n;
  }
};
