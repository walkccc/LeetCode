class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int ans = 0;
    // dp[i] := the minimum tail of all increasing subseqs with length i + 1
    // it's easy to see that dp must be an increasing array
    vector<int> dp(nums.size());

    for (const int num : nums) {
      int l = 0;
      int r = ans;
      // find the first index l in dp[0..ans) s.t. dp[l] >= num
      while (l < r) {
        const int m = l + (r - l) / 2;
        if (dp[m] < num)
          l = m + 1;
        else
          r = m;
      }
      dp[l] = num;
      // if didn't find any number in dp[0..ans) that is >= num, it means we
      // can append num in the current increasing subsequence
      if (l == ans)
        ++ans;
    }

    return ans;
  }
};