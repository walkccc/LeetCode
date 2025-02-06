class Solution {
 public:
  // Same as 2873. Maximum Value of an Ordered Triplet I
  long long maximumTripletValue(vector<int>& nums) {
    long ans = 0;
    int maxDiff = 0;  // max(nums[i] - nums[j])
    int maxNum = 0;   // max(nums[i])

    for (const int num : nums) {
      ans = max(ans, static_cast<long>(maxDiff) * num);  // num := nums[k]
      maxDiff = max(maxDiff, maxNum - num);              // num := nums[j]
      maxNum = max(maxNum, num);                         // num := nums[i]
    }

    return ans;
  }
};
