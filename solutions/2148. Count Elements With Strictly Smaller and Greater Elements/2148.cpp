class Solution {
 public:
  int countElements(vector<int>& nums) {
    const int mn = ranges::min(nums);
    const int mx = ranges::max(nums);
    return ranges::count_if(
        nums, [&](const int num) { return mn < num && num < mx; });
  }
};
