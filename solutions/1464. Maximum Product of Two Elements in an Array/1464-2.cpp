class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    const auto maxIt1 = ranges::max_element(nums);
    *maxIt1 *= -1;
    const int max2 = ranges::max(nums);
    *maxIt1 *= -1;
    return (*maxIt1 - 1) * (max2 - 1);
  }
};
