class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int task : tasks)
      ++count[task];

    // Freq = 1 -> impossible
    // Freq = 2 -> needs 1 round
    // Freq = 3 -> needs 1 round
    // Freq = 3k                           -> needs k rounds
    // Freq = 3k + 1 = 3 * (k - 1) + 2 * 2 -> needs k + 1 rounds
    // Freq = 3k + 2 = 3 * k       + 2 * 1 -> needs k + 1 rounds
    for (const auto& [_, freq] : count)
      if (freq == 1)
        return -1;
      else
        ans += (freq + 2) / 3;

    return ans;
  }
};
