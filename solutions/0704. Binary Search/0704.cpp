class Solution {
 public:
  int search(vector<int>& nums, int target) {
    const auto it = lower_bound(nums.begin(), nums.end(), target);
    return (it == nums.cend() || *it != target) ? -1
                                                : distance(nums.begin(), it);
  }
};
