class Solution {
  public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
    final int n = req_skills.length;
    final int nSkills = 1 << n;
    Map<String, Integer> skillToId = new HashMap();
    // dp[i] := the minimum people's indices to cover skillset of mask i
    List<Integer>[] dp = new List[nSkills];
    dp[0] = new ArrayList<>();

    for (int i = 0; i < req_skills.length; ++i)
      skillToId.put(req_skills[i], i);

    for (int i = 0; i < people.size(); ++i) {
      final int currSkill = getSkill(people.get(i), skillToId);
      for (int j = 0; j < nSkills; ++j) {
        if (dp[j] == null)
          continue;
        final int newSkillSet = currSkill | j;
        if (newSkillSet == j) // Adding people[i] doesn't increase skill set
          continue;
        if (dp[newSkillSet] == null || dp[newSkillSet].size() > dp[j].size() + 1) {
          dp[newSkillSet] = new ArrayList<>(dp[j]);
          dp[newSkillSet].add(i);
        }
      }
    }

    return dp[nSkills - 1].stream().mapToInt(Integer::intValue).toArray();
  }

  private int getSkill(List<String> person, Map<String, Integer> skillToId) {
    int mask = 0;
    for (final String skill : person)
      if (skillToId.containsKey(skill))
        mask |= 1 << skillToId.get(skill);
    return mask;
  }
}
