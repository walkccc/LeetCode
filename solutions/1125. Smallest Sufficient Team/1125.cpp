class Solution {
 public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                     vector<vector<string>>& people) {
    const int n = req_skills.size();
    const int nSkills = 1 << n;
    unordered_map<string, int> skillToId;
    // dp[i] := the minimum people's indices to cover skillset of mask i
    unordered_map<int, vector<int>> dp;
    dp.reserve(nSkills);  // Avoid rehash.
    dp[0] = {};

    for (int i = 0; i < n; ++i)
      skillToId[req_skills[i]] = i;

    auto getSkill = [&](const vector<string>& person) {
      int mask = 0;
      for (const string& skill : person)
        if (const auto it = skillToId.find(skill); it != skillToId.cend())
          mask |= 1 << it->second;
      return mask;
    };

    for (int i = 0; i < people.size(); ++i) {
      const int currSkill = getSkill(people[i]);
      for (const auto& [mask, indices] : dp) {
        const int newSkillSet = mask | currSkill;
        if (newSkillSet == mask)  // Adding people[i] doesn't increase skill set
          continue;
        if (!dp.contains(newSkillSet) ||
            dp[newSkillSet].size() > indices.size() + 1) {
          dp[newSkillSet] = indices;
          dp[newSkillSet].push_back(i);
        }
      }
    }

    return dp[nSkills - 1];
  }
};
