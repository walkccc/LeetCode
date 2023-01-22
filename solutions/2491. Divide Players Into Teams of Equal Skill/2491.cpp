class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    const int n = skill.size();
    const int teamSkill = accumulate(begin(skill), end(skill), 0) / (n / 2);
    long long ans = 0;
    unordered_map<int, int> count;

    for (const int s : skill)
      ++count[s];

    for (const auto& [s, freq] : count) {
      const int requiredSkill = teamSkill - s;
      if (!count.count(requiredSkill) || count[requiredSkill] != freq)
        return -1;
      ans += static_cast<long long>(s) * requiredSkill * freq;
    }

    return ans / 2;
  }
};
