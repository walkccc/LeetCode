class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    int target = 1;

    for (const int num : nums)
      if (num != target) {
        target ^= 1;
        ++ans;
      }

    return ans;
  }
};
