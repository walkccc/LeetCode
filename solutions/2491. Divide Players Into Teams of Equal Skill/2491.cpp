class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    const int n = skill.size();
    const int teamSkill = accumulate(skill.begin(), skill.end(), 0) / (n / 2);
    long ans = 0;
    unordered_map<int, int> count;

    for (const int s : skill)
      ++count[s];

    for (const auto& [s, freq] : count) {
      const int requiredSkill = teamSkill - s;
      if (const auto it = count.find(requiredSkill);
          it == count.cend() || it->second != freq)
        return -1;
      ans += static_cast<long>(s) * requiredSkill * freq;
    }

    return ans / 2;
  }
};
