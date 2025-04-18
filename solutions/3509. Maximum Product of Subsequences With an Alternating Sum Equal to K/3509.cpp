enum class State {
  kFirst,     // first element - add to sum and start product
  kSubtract,  // second element - subtract from sum and multiply product
  kAdd        // third element - add to sum and multiply product
};

class Solution {
 public:
  int maxProduct(vector<int>& nums, int k, int limit) {
    if (abs(k) > accumulate(nums.begin(), nums.end(), 0))
      return -1;
    unordered_map<string, int> mem;
    const int ans = maxProduct(nums, 0, 1, State::kFirst, k, limit, mem);
    return ans == kMin ? -1 : ans;
  }

 private:
  static constexpr int kMin = -5000;

  int maxProduct(const vector<int>& nums, int i, int product, State state,
                 int k, int limit, unordered_map<string, int>& mem) {
    if (i == nums.size())
      return k == 0 && state != State::kFirst && product <= limit ? product
                                                                  : kMin;
    const string key = to_string(i) + "," + to_string(k) + "," +
                       to_string(product) + "," +
                       to_string(static_cast<int>(state));
    if (mem.contains(key))
      return mem[key];
    int res = maxProduct(nums, i + 1, product, state, k, limit, mem);
    if (state == State::kFirst)
      res = max(res, maxProduct(nums, i + 1, nums[i], State::kSubtract,
                                k - nums[i], limit, mem));
    if (state == State::kSubtract)
      res = max(res, maxProduct(nums, i + 1, min(product * nums[i], limit + 1),
                                State::kAdd, k + nums[i], limit, mem));
    if (state == State::kAdd)
      res = max(res, maxProduct(nums, i + 1, min(product * nums[i], limit + 1),
                                State::kSubtract, k - nums[i], limit, mem));
    return mem[key] = res;
  }
};
