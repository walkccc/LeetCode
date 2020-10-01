class NumArray {
 public:
  NumArray(vector<int>& nums) : prefixSum(nums.size() + 1) {
    for (int i = 1; i <= nums.size(); ++i)
      prefixSum[i] += prefixSum[i - 1] + nums[i - 1];
  }

  int sumRange(int i, int j) {
    return prefixSum[j + 1] - prefixSum[i];
  }

 private:
  vector<int> prefixSum;
};