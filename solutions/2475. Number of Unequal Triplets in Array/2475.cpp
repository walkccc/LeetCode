// Assume that we have 4 kinds of numbers a, b, c, and d in the count map.
//
// What we want is:
//   cnt[a] * cnt[b] * cnt[c]
//   cnt[a] * cnt[b] * cnt[d]
//   cnt[a] * cnt[c] * cnt[d]
//   cnt[b] * cnt[c] * cnt[d]
//
// The above combinations can be reduced as:
//
// prev                       | curr   | next
// ----------------------------------------------------------------
// (0)                        * cnt[a] * (cnt[b] + cnt[c] + cnt[d])
// (cnt[a])                   * cnt[b] * (cnt[c] + cnt[d])
// (cnt[a] + cnt[b])          * cnt[c] * (cnt[d])
// (cnt[a] + cnt[b] + cnt[c]) * cnt[d] * (0)

class Solution {
 public:
  int unequalTriplets(vector<int>& nums) {
    int ans = 0;
    int prev = 0;
    int next = nums.size();
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [_, freq] : count) {
      next -= freq;
      ans += prev * freq * next;
      prev += freq;
    }

    return ans;
  }
};
