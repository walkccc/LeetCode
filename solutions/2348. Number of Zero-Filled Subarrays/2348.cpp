class Solution {
 public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long ans = 0;
    int indexBeforeZero = -1;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i])
        indexBeforeZero = i;
      else
        ans += i - indexBeforeZero;

    return ans;
  }
};
