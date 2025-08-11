class Solution {
 public:
  vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
    vector<int> lengths;
    vector<int> pows;

    ranges::sort(nums);

    for (const int num : nums) {
      lengths.push_back(to_string(num).length());
      pows.push_back(static_cast<int>(pow(10, lengths.back())) % k);
    }

    vector<vector<int>> mem(1 << nums.size(), vector<int>(k, -1));
    return dp(nums, pows, mem, k, 0, 0) ? reconstruct(nums, pows, mem, k, 0, 0)
                                        : vector<int>();
  }

 private:
  // Returns true if there is a way to form a number divisible by `k` using the
  // numbers in `nums`, where nums[i] is used iff `mask & (1 << i)`.
  bool dp(const vector<int>& nums, const vector<int>& pows,
          vector<vector<int>>& mem, int k, int mask, int mod) {
    if (mem[mask][mod] != -1)
      return mem[mask][mod] == 1;
    if (mask == (1 << nums.size()) - 1)
      return mod == 0;
    for (int i = 0; i < nums.size(); ++i)
      if ((mask >> i & 1) == 0) {
        const int newMod = (mod * pows[i] + nums[i]) % k;
        if (dp(nums, pows, mem, k, mask | 1 << i, newMod))
          return mem[mask][mod] = 1;
      }
    return mem[mask][mod] = 0;
  }

  // Reconstructs the numbers that form a number divisible by `k` using the
  // numbers in `nums`, where nums[i] is used iff `mask & (1 << i)`.
  vector<int> reconstruct(const vector<int>& nums, const vector<int>& pows,
                          vector<vector<int>>& mem, int k, int mask, int mod) {
    for (int i = 0; i < nums.size(); ++i)
      if ((mask >> i & 1) == 0) {
        const int newMod = (mod * pows[i] + nums[i]) % k;
        if (dp(nums, pows, mem, k, mask | 1 << i, newMod)) {
          vector<int> res{nums[i]};
          vector<int> rest =
              reconstruct(nums, pows, mem, k, mask | 1 << i, newMod);
          ranges::copy(rest, ranges::back_inserter(res));
          return res;
        }
      }
    return {};
  }
};
