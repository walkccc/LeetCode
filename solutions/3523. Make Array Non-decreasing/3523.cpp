class Solution {
 public:
  int maximumPossibleSize(vector<int>& nums) {
    int ans = 0;
    int prev = 0;

    for (const int num : nums)
      if (num >= prev) {
        prev = num;
        ++ans;
      }

    return ans;
  }
};
