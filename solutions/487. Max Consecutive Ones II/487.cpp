class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int zeros = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (nums[r] == 0)
        ++zeros;
      while (zeros == 2)
        if (nums[l++] == 0)
          --zeros;
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
