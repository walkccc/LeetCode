class Solution {
 public:
  int countElements(vector<int>& nums) {
    const int min = ranges::min(nums);
    const int max = ranges::max(nums);
    return count_if(nums.begin(), nums.end(),
                    [&](const int num) { return min < num && num < max; });
  }
};
