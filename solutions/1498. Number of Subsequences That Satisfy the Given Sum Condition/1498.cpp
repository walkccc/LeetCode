class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    int ans = 0;
    vector<int> pows(n, 1);  // pows[i] = 2^i % kMod

    for (int i = 1; i < n; ++i)
      pows[i] = pows[i - 1] * 2 % kMod;

    sort(begin(nums), end(nums));

    for (int l = 0, r = n - 1; l <= r;)
      if (nums[l] + nums[r] <= target) {
        ans += pows[r - l];
        ans %= kMod;
        ++l;
      } else {
        --r;
      }

    return ans;
  }
};
