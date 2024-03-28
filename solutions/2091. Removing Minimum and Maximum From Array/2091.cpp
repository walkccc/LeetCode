class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    const int n = nums.size();
    int a = ranges::min_element(nums) - nums.begin();
    int b = ranges::max_element(nums) - nums.begin();
    if (a > b)
      swap(a, b);
    return min({a + 1 + n - b, b + 1, n - a});
  }
};
