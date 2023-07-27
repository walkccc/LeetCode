class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    const int n = nums.size();
    int a = min_element(nums.begin(), nums.end()) - nums.begin();
    int b = max_element(nums.begin(), nums.end()) - nums.begin();
    if (a > b)
      swap(a, b);
    return min({a + 1 + n - b, b + 1, n - a});
  }
};
