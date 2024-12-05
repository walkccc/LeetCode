class Solution {
 public:
  int maxSubarrays(vector<int>& nums) {
    int ans = 0;
    int score = 0;

    for (const int num : nums) {
      score = score == 0 ? num : score & num;
      if (score == 0)
        ++ans;
    }

    return max(1, ans);
  }
};
