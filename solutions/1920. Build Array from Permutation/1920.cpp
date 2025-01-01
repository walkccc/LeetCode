class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    const int n = nums.size();

    for (int i = 0; i < n; ++i)
      nums[i] += n * (nums[nums[i]] % n);

    for (int i = 0; i < n; ++i)
      nums[i] /= n;

    return nums;
  }
};
