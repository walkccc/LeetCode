class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int ans = 0;
    int l = 0;
    int r = nums.size() - 1;
    long leftSum = nums.front();
    long rightSum = nums.back();

    while (l < r)
      if (leftSum < rightSum) {
        leftSum += nums[++l];
        ++ans;
      } else if (leftSum > rightSum) {
        rightSum += nums[--r];
        ++ans;
      } else {  // leftSum == rightSum
        leftSum = nums[++l];
        rightSum = nums[--r];
      }

    return ans;
  }
};
