class Solution {
 public:
  int countElements(vector<int>& nums) {
    const int min = ranges::min(nums);
    const int max = ranges::max(nums);
    return ranges::count_if(
        nums, [&](const int num) { return min < num && num < max; });
  }
};
