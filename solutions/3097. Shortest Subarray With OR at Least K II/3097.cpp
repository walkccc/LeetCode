class Solution {
 public:
  // Same as 3095. Shortest Subarray With OR at Least K I
  int minimumSubarrayLength(vector<int>& nums, int k) {
    constexpr int kMax = 50;
    const int n = nums.size();
    int ans = n + 1;
    int ors = 0;
    vector<int> count(kMax + 1);

    for (int l = 0, r = 0; r < n; r++) {
      ors = orNum(ors, nums[r], count);
      while (ors >= k && l <= r) {
        ans = min(ans, r - l + 1);
        ors = undoOrNum(ors, nums[l], count);
        ++l;
      }
    }

    return (ans == n + 1) ? -1 : ans;
  }

 private:
  static constexpr int kMaxBit = 30;

  int orNum(int ors, int num, vector<int>& count) {
    for (int i = 0; i < kMaxBit; ++i)
      if (num >> i & 1 && ++count[i] == 1)
        ors += 1 << i;
    return ors;
  }

  int undoOrNum(int ors, int num, vector<int>& count) {
    for (int i = 0; i < kMaxBit; ++i)
      if (num >> i & 1 && --count[i] == 0)
        ors -= 1 << i;
    return ors;
  }
};
