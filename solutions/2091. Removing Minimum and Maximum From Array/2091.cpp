class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    const int n = nums.size();
    int a = min_element(begin(nums), end(nums)) - begin(nums);
    int b = max_element(begin(nums), end(nums)) - begin(nums);
    if (a > b)
      swap(a, b);
    return min({a + 1 + n - b, b + 1, n - a});
  }
};
