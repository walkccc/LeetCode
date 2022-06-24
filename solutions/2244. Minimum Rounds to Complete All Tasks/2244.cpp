class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const auto& t : tasks)
      ++count[t];

    // freq = 1 -> impossible
    // freq = 2 -> needs 1 round
    // freq = 3 -> needs 1 round
    // freq = 3k                           -> needs k rounds
    // freq = 3k + 1 = 3 * (k - 1) + 2 * 2 -> needs k + 1 rounds
    // freq = 3k + 2 = 3 * k       + 2 * 1 -> needs k + 1 rounds
    for (const auto& [_, freq] : count)
      if (freq == 1)
        return -1;
      else
        ans += (freq + 2) / 3;

    return ans;
  }
};
