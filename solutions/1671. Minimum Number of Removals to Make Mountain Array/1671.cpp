class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    vector<int> l = lengthOfLIS(nums);
    vector<int> r = reversed(lengthOfLIS(reversed(nums)));
    int maxMountainSeq = 0;

    for (int i = 0; i < nums.size(); ++i)
      if (l[i] > 1 && r[i] > 1)
        maxMountainSeq = max(maxMountainSeq, l[i] + r[i] - 1);

    return nums.size() - maxMountainSeq;
  }

 private:
  vector<int> lengthOfLIS(vector<int> nums) {
    // tail[i] := the minimum tail of all increasing subseqs having length i + 1
    // it's easy to see that tail must be an increasing array
    vector<int> tail;

    // dp[i] := length of LIS ending at nums[i]
    vector<int> dp(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];
      if (tail.empty() || num > tail.back()) {
        tail.push_back(num);
      } else {
        int l = 0;
        int r = tail.size();
        // find the first index l in tail s.t. tail[l] >= num
        while (l < r) {
          const int m = (l + r) / 2;
          if (tail[m] >= num)
            r = m;
          else
            l = m + 1;
        }
        tail[l] = num;
      }
      dp[i] = tail.size();
    }

    return dp;
  }

  vector<int> reversed(const vector<int>& nums) {
    return {rbegin(nums), rend(nums)};
  }
};
